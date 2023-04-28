#include <Pixy2.h>

/***************************************************************************
 * DÉCLARATION ET INITIALISATION DES VARIABLES ET OBJETS POUR LE PROGRAMME
 ***************************************************************************/

// déclarer le matériel
Pixy2 pixy;
#define forward 410
#define slowForward 490
#define backward 590
#define slowBackward 510
#define stopServo 500
#define centerX 0
#define offsetX 20

#define piezo 4

#define leftWhisker 5
#define rightWhisker 7
#define pressed 0

// définir les états
int currentState;
#define SET_TARGET 0
#define FIND_TARGET 1
#define MOVE_TO_TARGET 2
#define PARKED 3
#define NO_TARGET_FOUND 4
#define END 5

// déclarer une variable de décompte
int timer;

// déclarer une cible
int target;
#define stopWidth 200  // largeur de la signature


void setup() {
  pixy.init();
  currentState = SET_TARGET;
  timer = 10000;  // 10 secondes
}

/*************************************************************************
 * DÉFINIR LES ACTIONS POUR CHAQUE ÉTAT DANS DES FONCTIONS
 *
 * C'est important de noter que chaque fonction inclut une condition pour
 * passer au prochain état (en modifiant la variable currentState)
 *
 *************************************************************************/

// Pour l'état SET_TARGET
void setTarget() {
  // attendre que le bouton gauche soit pressé avant de capter la signature
  while (leftWhisker != pressed) {
    delay(20);
  }
  pixy.ccc.getBlocks();
  target = pixy.ccc.blocks[0].m_signature;

  // attendre que le bouton droit soit pressé avant de passer au prochain état
  while (rightWhisker != pressed) {
    delay(20);
  }
  currentState = FIND_TARGET;
}

// pour l'état FIND_TARGET
void findTarget() {

  // si le temps est écoulé sans détection de signature
  if (timer <= 0) {
    currentState = NO_TARGET_FOUND;
    return;  // mettre immédiatement fin à la fonction
  }

  // sinon on cherche encore un bloc avec la signature cible

  // obtenir les blocs visibles
  pixy.ccc.getBlocks();

  // vérifier si la signature cible est dans les blocs détectés
  bool targetFound = false;
  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    if (pixy.ccc.blocks[i].m_signature == target) targetFound = true;
  }

  // si la cible est en vu, changer d'état
  if (targetFound) {
    currentState = MOVE_TO_TARGET;

  } else {
    // sinon pivoter quelques degrés vers la gauche et mettre à jour le décompte
    int dt = 100;
    pixy.setServos(slowForward, slowBackward);
    delay(dt);
    pixy.setServos(stopServo, stopServo);
    timer -= dt;
  }
}

// pour l'état MOVE_TO_TARGET
void moveToTarget() {
  // capter les blocs en vu
  pixy.ccc.getBlocks();

  // prendre la largeur du bloc avec la signature cible
  int visibleWidth;
  int i;
  for (i = 0; i < pixy.ccc.numBlocks; i++) {
    if (pixy.ccc.blocks[i].m_signature == target) {
      visibleWidth = pixy.ccc.blocks[i].m_width;
      break;  // arrêter de passer à travers les blocs et conserver la valeur d'i
    }
  }

  // si la largeur de la cible est plus grande que la valeur limite, on a fini
  if (visibleWidth >= stopWidth) {
    pixy.setServos(stopServo, stopServo);
    currentState = PARKED;
    return;  // mettre immédiatement fin à la fonction
  }

  // sinon, avancer vers le bloc en se centrant
  if (pixy.ccc.blocks[i].m_x > centerX + offsetX) {  
    // si le bloc est à la droite
    pixy.setServos(slowBackward, forward); // tourner vers la droite
  } else if (pixy.ccc.blocks[i].m_x < centerX - offsetX) { 
    // sinon si le bloc est à la gauche
    pixy.setServos(backward, slowForward); // tourner vers la gauche
  } else {  
    // sinon aller droit devant
    pixy.setServos(backward, forward);
  }
}

// pour l'état PARKED
void parked() {
  tone(piezo, 800);  // ton de succès
  delay(1000);
  noTone(piezo);
  currentState = END;
}

// pour l'état NO_TARGET_FOUND
void noTargetFound() {
  tone(piezo, 400);  // ton d'erreur
  delay(1000);
  noTone(piezo);
  currentState = END;
}

/**********************************************
 * IMPLÉMENTATION DE LA MACHINE À ÉTATS FINIS
 **********************************************/

void loop() {
  /*
    Cascade if-else if-else pour chaque état possible.
  */
  if (currentState == SET_TARGET) setTarget();
  else if (currentState == FIND_TARGET) findTarget();
  else if (currentState == MOVE_TO_TARGET) moveToTarget();
  else if (currentState == PARKED) parked();
  else if (currentState == NO_TARGET_FOUND) noTargetFound();
  else if (currentState == END) delay(1000);  // ne rien faire sauf passer le temps
  else currentState = NO_TARGET_FOUND;        // donnera un ton d'erreur
}

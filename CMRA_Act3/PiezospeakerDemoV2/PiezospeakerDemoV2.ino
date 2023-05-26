// Ajout de code externe
#include <Servo.h>

// Déclaration des variables globales
Servo servoLeft;        // moteur gauche
Servo servoRight;       // moteur droit
#define speakerPort  4  // prise où le haut-parleur est connecté

/*
 * Fonctions obligatoires, appelées automatiquement par Arduino
 */

// Appelée une seule fois lors du lancement du programme
void setup() 
{
  servoLeft.attach(10);  // lier le moteur gauche à la prise 10
  servoRight.attach(11); // lier le moteur gauche à la prise 11

  tone(speakerPort, 2000, 1000); // jouer un ton de 2kHz pendant 1s
  delay(1000);                   // bloquer le programme pendant 1s
}

// Appelée dans une boucle infinie après la fonction setup()
void loop() 
{
  forward(1000); // bouger vers l'avant pendant 1s
  tone(speakerPort, 500, 1000); // jouer un ton de 500Hz pendant 1s
  delay(1000);

  turnRight(400); // tourner vers la droite pendant 0,4s
  tone(speakerPort, 1500, 1000); // jouer un ton de 1,5kHz pendant 1s
  delay(1000);
}

/*
 * Fonctions que nous avons définies nous-mêmes
 */

// instructions pour faire avancer le robot pendant un temps spécifique 
void forward(int time)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

// instructions pour faire pivoter le robot vers la droite pendant un temps spécifique
void turnRight(int time){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(time);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

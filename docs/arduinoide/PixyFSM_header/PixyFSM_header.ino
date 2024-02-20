#include <Arduino.h>
#include "ShieldBot.h" // déclarations réutilisables

// variables globales déclarées dans ShieldBot.h

void setup() {
  initialiseShieldBot(); // déclaré dans ShieldBot.h
  currentState = SET_TARGET;
  timer = 10000;  // 10 secondes
  tone(piezo, 800, 1000); // ton qui signale que le programme est prêt
}

/**********************************************
 * IMPLÉMENTATION DE LA MACHINE À ÉTATS FINIS
 **********************************************/

void loop() {
  /*
    Cascade if-else if-else pour chaque état possible.
    Chaque fonction est définie dans ShieldBot.h
  */
  if (currentState == SET_TARGET) setTarget();
  else if (currentState == FIND_TARGET) findTarget();
  else if (currentState == MOVE_TO_TARGET) moveToTarget();
  else if (currentState == PARKED) parked();
  else if (currentState == NO_TARGET_FOUND) noTargetFound();
  else if (currentState == END) end();
  else currentState = NO_TARGET_FOUND;  // en cas d'erreur
}

// ShieldBot Navigation with Whiskers
// Robot plays different tones based on whether
// both, one, or neither of the whiskers are pressed in.

/*
 * Remplacer les #define avec des variables et des fonctions
 * Renommer certaines des données liées aux moustaches.
 * Modification par : M. Crowley, 2023-03
 */

// Variables and functions for storing whisker data to improve code readibility
int leftWhisker = 7;
int rightWhisker = 5;
int rightWhiskerState() {
  return digitalRead(leftWhisker);
}
int leftWhiskerState() {
  return digitalRead(rightWhisker);
} 
int pressed = 0;
int released = 1;

// Variable for storing speaker port
int speakerPort = 4;

void setup()                                 // Built-in setup() initialization function runs once
{
  pinMode(leftWhisker, INPUT);               // Set right whisker as input
  pinMode(rightWhisker, INPUT);              // Set left whisker as input

  tone(speakerPort, 2000, 1000);             // Play tone for 1 second
  delay(1000);                               // Delay for tone to finish
}

void loop()                                  // Built-in loop repeats forever after setup() function finishes
{
  if (leftWhiskerState() == pressed && rightWhiskerState() == pressed) {  // If both whiskers are pressed...
    tone(speakerPort, 2000);
  } else if (leftWhiskerState() == pressed) {    // If only left whisker is pressed...
    tone(speakerPort, 1000);        
  } else if (rightWhiskerState() == pressed) {     // If only right whisker contact...
    tone(speakerPort, 500);
  } else {                                   // Else (no whisker is pressed)...
    noTone(speakerPort);                   
  }
}

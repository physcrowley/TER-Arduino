// Nighttime Vacuume
// Robot drives through an environment and moves differently based on whether
// both, one, or neither of the whiskers are pressed in, WHILE the lights in 
// the room are turned off (or low).

/*
 * Remplacer les #define avec des variables et des fonctions
 * Rendre explicite les numéros des prises pour les différents capteurs.
 * Modification par : M. Crowley, 2023-03
 */

// Variables for storing various servomotor speeds
int stopServo = 1500;
int forward = 1700;
int reverse = 1300;

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

// Set speaker pin
int speakerPort = 4;

// Accessing the photoresistor
int phototransistor = A3; // connected to analog pin 3
int phototransistorState() {
  return analogRead(phototransistor);
}

//Servo Include Library and right and left servo definitions
#include <Servo.h>
Servo servoLeft;
Servo servoRight;

void setup()                                 // Built-in setup() initialization function runs once
{
  pinMode(rightWhisker, INPUT);                         // Set right whisker to input pin 7
  pinMode(leftWhisker, INPUT);                         // Set left whisker to input pin 5

  servoLeft.attach(10);                      // Set left servo to pin 10
  servoRight.attach(11);                     // Set right servo to pin 11
  
  Serial.begin(9600);
  tone(speakerPort, 2000, 1000);             // Play tone for 1 second
  delay(1000);                               // Delay for tone to finish
}

void loop()                                  // Main loop auto-repeats
{
  Serial.println(phototransistorState());           // Prints phototransistor level
  
  if (phototransistorState() < 50)
  {
    if (leftWhiskerState() == pressed && rightWhiskerState() == pressed)  // If both whiskers are pressed...
    {
      // ...Move Backwards
      servoLeft.writeMicroseconds(reverse);    // Left wheel clockwise
      servoRight.writeMicroseconds(forward);   // Right wheel counterclockwise
      delay(1000);                             // Back up 1 second

      // Turn Left
      servoLeft.writeMicroseconds(reverse);    // Left wheel clockwise
      servoRight.writeMicroseconds(reverse);   // Right wheel clockwise
      delay(800);                              // Turn left about 120 degrees
    }
    else if (leftWhiskerState() == pressed)           // Else, If only left whisker is pressed...
    {
      // ...Move Backwards
      servoLeft.writeMicroseconds(reverse);    // Left wheel clockwise
      servoRight.writeMicroseconds(forward);   // Right wheel counterclockwise
      delay(1000);                             // Back up 1 second

      // Turn Right
      servoLeft.writeMicroseconds(forward);    // Left wheel counterclockwise
      servoRight.writeMicroseconds(forward);   // Right wheel counterclockwise
      delay(400);                              // Maneuver for time ms
    }
    else if (rightWhiskerState() == pressed)          // Else, If only right whisker contact...
    {
      // ...Move Backwards
      servoLeft.writeMicroseconds(reverse);    // Left wheel clockwise
      servoRight.writeMicroseconds(forward);   // Right wheel counterclockwise
      delay(1000);                             // Back up 1 second

      // Turn Left
      servoLeft.writeMicroseconds(reverse);    // Left wheel clockwise
      servoRight.writeMicroseconds(reverse);   // Right wheel clockwise
      delay(400);
    }
    else                                       // Else (no whisker is pressed)...
    {
      // ...Move Forward
      servoLeft.writeMicroseconds(forward);    // Left wheel counterclockwise
      servoRight.writeMicroseconds(reverse);   // Right wheel clockwise
    }
  }
  else
  {
    // Stop Motors
    servoLeft.writeMicroseconds(stopServo);    
    servoRight.writeMicroseconds(stopServo);
  }

}

// Whisker Setup
// Test that the whiskers are correctly working by driving forward
// if the right whisker is not pressed in.

/*
 * Remplacer les #define avec des variables et des fonctions
 * Modification par : M. Crowley, 2023-03
 */

// Variables for storing various servomotor speeds
int stopServo = 1500;
int forward = 1700;
int reverse = 1300;

// Variable for storing speaker port
int speakerPort = 4;

// Variable and function for storing whisker data to improve code readibility
int whisker = 7;
int whiskerRight() { 
  return digitalRead(whisker); // whisker sur la prise 7 en mode lecture
}
int pressed = 0;

//Servo Include Library and right and left servo definitions
#include <Servo.h>
Servo servoLeft;
Servo servoRight;

void setup()                                 // Built-in setup() initialization function runs once
{
  pinMode(whisker, INPUT);                         // Set right whisker to input pin 7

  servoLeft.attach(10);                      // Set left servo to pin 10
  servoRight.attach(11);                     // Set right servo to pin 11

  tone(speakerPort, 2000, 1000);             // Play tone for 1 second
  delay(1000);                               // Delay for tone to finish
}
 
void loop()                                  // Built-in loop repeats forever after setup() function finishes
{
  if(whiskerRight() == pressed)                // If right whisker is pressed...
  {
    // ...stop.
    servoLeft.writeMicroseconds(stopServo);       
    servoRight.writeMicroseconds(stopServo);
  
  }
  else                                       // Else (right whisker is not pressed)...
  {
    // ...move forward. 
    servoLeft.writeMicroseconds(forward);    // Left wheel counterclockwise
    servoRight.writeMicroseconds(reverse);   // Right wheel clockwise
  }
}

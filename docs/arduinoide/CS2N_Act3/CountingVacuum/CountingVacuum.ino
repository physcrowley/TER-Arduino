// Wall Counting with ShieldBot Whiskers
// Count how many walls the ShieldBot should detect with its whiskers,
// then allow the ShieldBot to drive and detect those walls.

// Macros for storing various servomotor speeds
#define stopServo 1500
#define forward 1700
#define reverse 1300

// Macros for storing whisker data to improve code readibility
#define whiskerRight digitalRead(7)
#define whiskerLeft digitalRead(5)
#define pressed 0
#define released 1

// Macros for storing speaker and phototransistor ports
#define speakerPort 4
#define phototransistor analogRead(A3)

//Servo Include Library and right and left servo definitions
#include <Servo.h>
Servo servoLeft;
Servo servoRight;

// Variable to store the number of desired walls for detection
int wallCount = 0;

void setup()                                 // Built-in setup() initialization function runs once
{
  pinMode(7, INPUT);                         // Set right whisker to input pin 7
  pinMode(5, INPUT);                         // Set left whisker to input pin 5

  servoLeft.attach(10);                      // Set left servo to pin 10
  servoRight.attach(11);                     // Set right servo to pin 11

  tone(speakerPort, 2000, 1000);             // Play tone for 1 second
  delay(1000);                               // Delay for tone to finish

  while (whiskerLeft == released)            // While the left whisker is released (not pressed)...
  {
    if (whiskerRight == pressed)             // If the right whisker is pressed...
    {
      while (whiskerRight == pressed)        // Loop to wait for the right whisker to be released to avoid double counting, then...
      {
        delay(10);
      }
      tone(4, 1000, 250);                     // Play a tone for 250 milliseconds...
      delay(250);
      wallCount = wallCount + 1;              // ...increment the variable used to store the number of walls for detection by one.
    }
  }
  tone(speakerPort, 2000, 1000);              // Play tone for 1 second more second after the left whisker has been pressed
  delay(1000);
}

void loop()                                   // Built-in loop repeats forever after setup() function finishes
{
  if (wallCount > 0)                          // If the wallCount variable is greater than 0...
  {
    //Drive forward while neither whisker is pressed
    while (whiskerLeft == released && whiskerRight == released)
    {
      servoLeft.writeMicroseconds(forward);
      servoRight.writeMicroseconds(reverse);
    }

    if (whiskerLeft == pressed && whiskerRight == pressed)   // If both whiskers are pressed...
    {
      // Move Backwards for 1 second
      servoLeft.writeMicroseconds(reverse);
      servoRight.writeMicroseconds(forward);
      delay(1000);

      // Turn Right for 0.8 seconds
      servoLeft.writeMicroseconds(forward);
      servoRight.writeMicroseconds(forward);
      delay(800);
    }
    else if (whiskerLeft == pressed)               // If the left whisker is pressed...
    {
      // Move Backwards for 1 second
      servoLeft.writeMicroseconds(reverse);
      servoRight.writeMicroseconds(forward);
      delay(1000);

      // Turn Right for 0.4 seconds
      servoLeft.writeMicroseconds(forward);
      servoRight.writeMicroseconds(forward);
      delay(400);
    }
    else if (whiskerRight == pressed)       // ...else, if the right whisker is pressed...
    {
      // Move Backwards for 1 second
      servoLeft.writeMicroseconds(reverse);
      servoRight.writeMicroseconds(forward);
      delay(1000);

      //Turn Left for 0.4 seconds
      servoLeft.writeMicroseconds(reverse);
      servoRight.writeMicroseconds(reverse);
      delay(400);
    }
    wallCount = wallCount - 1;            // decrement the variable by one.
  }
  else                                    // ...else, stop the robot.
  {
    servoLeft.writeMicroseconds(stopServo);
    servoRight.writeMicroseconds(stopServo);
  }
}

// Phototransistor Demo
// Demo Program to view what analog values the phototransistor provides

/*
 * Rempacer le #define avec des variables et une fonction
 * Modification par M. Crowley, 2023-03
 */

// Accessing the photoresistor
int phototransistor = A3; // connected to analog pin 3
int phototransistorState() {
  return analogRead(phototransistor);
}

void setup()                  // Built-in setup() initialization function runs once
{
  //Set the Serial Monitor to run
  Serial.begin(9600);
}

void loop()                   // Built-in loop repeats forever after setup() function finishes
{
  //Display the value from the phototransistor on the Serial Monitor
  Serial.println(phototransistorState());
}

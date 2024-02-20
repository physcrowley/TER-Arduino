// Light Level Pitch
// Adjust the frequency of the speaker tone based on the phototransistor value.

// Set speaker pin
int speakerPort = 4;

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
  // Integer Variable declared to store the frequency for the speaker
  int calculatedTone;
  // Calculate the frequency to send to the speaker by multiplying the phototransistor value by 2
  // Store the result in the calculatedTone Integer Variable
  calculatedTone = phototransistorState() * 2;
  
  //Display the calculated value on the Serial Monitor
  Serial.println(calculatedTone);

  if(calculatedTone < 100)    // If the calculatedTone variable is less than 100...
  {
    noTone(speakerPort);      // ...play no sound.
  }
  else                        // Else...
  {
    tone(speakerPort, calculatedTone);   // ...play the tone stored in the calculatedTone variable.
  }
}

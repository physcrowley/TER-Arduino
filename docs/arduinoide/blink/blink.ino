// Variable pour la broche du DEL incorporé à la carte
const int LED = 13;

void setup() {
  // Signaler que la broche fonctionne comme sortie
  pinMode(LED, OUTPUT);

}

void loop() {
  // Alterne entre un état allumé (HIGH) et éteint (LOW)
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // turn one way
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(1000);
  // turn the other way
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
}

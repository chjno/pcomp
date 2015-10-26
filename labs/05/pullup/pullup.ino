void setup() {
  pinMode(7, INPUT_PULLUP); // activates internal pull up resistors inside arduino
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, digitalRead(7));
}

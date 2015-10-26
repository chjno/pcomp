void setup() {
  pinMode(2, INPUT); // set pin 10 to be an input
  pinMode(9, OUTPUT); // set pin 5 to be an output
  Serial.begin(9600); //initialize serial communication
}

void loop() {
  if (digitalRead(10) == HIGH) {  // read the input, if it's HIGH
    Serial.println("High");
    digitalWrite(5, HIGH);        // turn on LED
    delay(500);                   // wait 500 ms
    digitalWrite(5, LOW);         // turn off LED
    delay(500);
  } else {                        // else if it's LOW
    Serial.println("Low");
    digitalWrite(5, LOW);         // turn off LED
  }
}

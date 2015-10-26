void setup() {
  //pinMode(9, OUTPUT); // set pin 5 to be an output
  Serial.begin(9600); //initialize serial communication

}

void loop() {
  int sensor = analogRead(A0);    // read sensor pin
  Serial.println(sensor);         // print value from sensor

  if (10 < sensor < 299) {
    tone(9, 200);
  } else if (300 < sensor < 599) {
    tone(9, 300);
  } else if (600 < sensor < 999) {
    tone(9, 400);
  } else {
    noTone(9);
  }
}

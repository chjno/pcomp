void setup() {
  Serial.begin(9600); //initialize serial communication
}

void loop() {
  int sensor = analogRead(A0);    // read sensor pin
  Serial.println(sensor);         // print value from sensor
  delay(1);                       // delay one ms
}

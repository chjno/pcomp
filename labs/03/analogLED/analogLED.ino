void setup() {
  Serial.begin(9600); //initialize serial communication
  pinMode(8, OUTPUT);
}

void loop() {
  int sensor = analogRead(A0);    // read sensor pin
  Serial.println(sensor);         // print value from sensor
  digitalWrite(8, HIGH);
  delay(sensor);                       // delay one ms
  digitalWrite(8, LOW);
  delay(sensor);
}

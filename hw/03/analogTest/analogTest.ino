void setup() {
  Serial.begin(9600); //initialize serial communication
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int sensor = analogRead(A0);    // read sensor pin
  Serial.println(sensor);         // print value from sensor
  
  
  if (sensor >= 0 && sensor < 299) {
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  } else if (sensor > 300 && sensor < 869) {
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  } else if (sensor > 870 && sensor < 929) {
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  } else if (sensor > 930 && sensor < 999) {
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(50);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(50);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(50);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {   // making sure there are bytes in the serial buffer to be read
    int input = Serial.read();
    analogWrite(9, input);
    
//    if (input == 'h') {
//      digitalWrite(9, HIGH);
//    } else if (input == 'l') {
//      digitalWrite(9, LOW);
//    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  while (Serial.available() <= 0) {
    Serial.println("Hello?");
    delay(300);
  }
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
      // to keep from continuously printing vals
      // once byte is read, buffer goes back to 0
  
  int xAxis = analogRead(A0);
  Serial.print(xAxis);
  Serial.print(",");
  
  int yAxis = analogRead(A1);
Serial.print(yAxis);
  Serial.print(",");

  
  int pushButton = digitalRead(2);
  Serial.println(pushButton);
  }
}

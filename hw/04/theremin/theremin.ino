void setup() {
  Serial.begin(9600);
}

void loop() {
  int fsrVal = analogRead(A0);
  Serial.println(fsrVal);            // 400-800

  

  int fsrMap = map(fsrVal,0,950,0,8);
  int notes[] = {200,400,600,800,1000,1200,1400,1600};
  
  tone(13,notes[fsrMap]);

}

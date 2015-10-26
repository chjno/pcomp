float c6 = 1046.5;
float d6 = 1174.7;
float e6 = 1318.5;
float f6 = 1396.9;
float g6 = 1568;
float a6 = 1760;
float b6 = 1975.5;
float c7 = 2093;
int melody[] = {c6, c6, g6, g6, a6, a6, g6, f6, f6, e6, e6, d6, d6, c6};
int duration[] = {250, 250, 250, 250, 250, 250, 500, 250, 250, 250, 250, 250, 250, 500};

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    tone(13, c6);
  } else if (digitalRead(3) == HIGH) {
    tone(13, d6);
  } else if (digitalRead(4) == HIGH) {
    tone(13, e6);
  } else if (digitalRead(5) == HIGH) {
    tone(13, f6);
  } else if (digitalRead(6) == HIGH) {
    tone(13, g6);
  } else if (digitalRead(7) == HIGH) {
    tone(13, a6);
  } else if (digitalRead(8) == HIGH) {
    tone(13, b6);
  } else if (digitalRead(9) == HIGH) {
    tone(13, c7);
  } else if (digitalRead(10) == HIGH) {
    for (int i = 0; i < 14; i++) {
      tone(13, melody[i], duration[i]);
      delay(duration[i] * 1.3);
      noTone(13);
      Serial.println(melody[i]);
    }
  } else {
    noTone(13);
  }
}

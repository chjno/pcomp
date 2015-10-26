int fret1pin = 2;
int fret2pin = 3;
int fret3pin = 4;
int string1pin = 8;
int string2pin = 9;
int string3pin = 10;
int string4pin = 11;
int string5pin = 12;
int string6pin = 13;

int fretPins[] = {fret1pin, fret2pin, fret3pin};
int stringPins[] = {string1pin, string2pin, string3pin, string4pin, string5pin, string6pin};

//int aChord[] = {0, 0, 2, 2, 2, 0};
//int dChord[] = {0, 0, 0, 2, 3, 2};
//int eChord[] = {0, 2, 2, 1, 0, 0};
//int gChord[] = {3, 2, 0, 0, 0, 3};
//int cChord[] = {0, 3, 2, 0, 1, 0};

int currentChord[] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  pinMode(string1pin, OUTPUT);
  pinMode(string2pin, OUTPUT);
  pinMode(string3pin, OUTPUT);
  pinMode(string4pin, OUTPUT);
  pinMode(string5pin, OUTPUT);
  pinMode(string6pin, OUTPUT);
  pinMode(fret1pin, INPUT);
  pinMode(fret2pin, INPUT);
  pinMode(fret3pin, INPUT);
}

void initStrings() {
  for (int i = 0; i < 6; i++) {
    currentChord[i] = 0;
  }
}

void loop() {
  for (int string = 0; string < 6; string++) {
    digitalWrite(stringPins[string], HIGH);
    for (int fret = 1; fret < 4; fret++) {
      if (digitalRead(fretPins[fret - 1]) == HIGH) {
        currentChord[string] = fret;
      }
    }
    digitalWrite(stringPins[string], LOW);
  }
  for (int i = 0; i < 6; i++) {
    Serial.print(currentChord[i]);
  }
  Serial.println();
  initStrings();
}

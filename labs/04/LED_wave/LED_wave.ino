int pinNumber[] = {3,5,6,9,10,11};

void setup() {

}

void loop() {
  for (int thisPin = 0; thisPin < 6; thisPin++) {
    int myPin = pinNumber[thisPin];

    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(myPin, brightness);
      delay(3);
    }

    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(myPin, brightness);
      delay(3);
    }
  }
}

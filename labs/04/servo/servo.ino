#include <Servo.h>
long lastServoMove = 0;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(7);    // tell arduino to control pin 7 w/ 
                        // servo library
}

void loop() {
  int sensor = analogRead(A0);
  int angle = map(sensor,0,1023,0,179);

  // refresh servo every 20 ms
  if (millis() - lastServoMove >= 20) {
    myServo.write(angle);
    lastServoMove = millis();
  }

}

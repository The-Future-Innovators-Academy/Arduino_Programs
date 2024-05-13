#include <Servo.h>

Servo servo;

int joystick1X = A0;
int buzzerPin = 8;

void setup() {
  servo.attach(9);

  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int joystick1XVal = analogRead(joystick1X); // 0 - 1023

  int servo1Pos = map(joystick1XVal, 0, 1023, 0, 180);

  servo.write(servo1Pos);

  Serial.print("Servo 1 Position: ");
  Serial.println(servo1Pos);

  if (servo1Pos == 0 || servo1Pos == 180){
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
  }

  delay(15);
}

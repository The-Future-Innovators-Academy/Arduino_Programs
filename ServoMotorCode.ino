#include <Servo.h>

Servo myservo1;
Servo myservo2;

int servoPin1 = 9;
int servoPin2 = 10;

void setup() {
  // Attach servos to defined pins
  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);

  servo1.write(0);
  servo2.write(180);

}

void loop() {
  for(int pos = 0; pos <= 180; pos++ ){
    servo1.write(pos);
    servo2.write(180 - pos);
  }

  delay(500);

  for(int pos = 180; pos >= 0; pos-- ){
    servo1.write(pos);
    servo2.write(180 - pos);
  }

  delay(500);

}

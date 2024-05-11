#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

const int chargePin = 8;
const int measurePin = A0;
const int startButtonPin = 7;
const float knownResistor = 10000.0;

void setup() {
  pinMode(chargePin, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);
  digitalWrite(chargePin, LOW);

  lcd.begin(16, 2);
  lcd.print("Capacitance Meter");
}

void loop() {
  // put your main code here, to run repeatedly:

}

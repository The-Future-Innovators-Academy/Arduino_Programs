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

float measureCapacitance(){
  digitalWrite(chargePin, LOW);
  delayMicroseconds(100);
  pinMode(measurePin, INPUT);

  unsigned long startTime = micros();
  digitalWrite(chargePin, HIGH);
  while(analogRead(measurePin) < 648){}

  unsigned long elapsedTime = micros() - startTime;

  float capacitance = (elapsedTime / 1000000.0) / (knownResistor * 0.632); // farads
  return capacitance * 1000000; // micro-farads
}


void loop() {
  if(digitalRead(startButtonPin) == LOW){
    float capacitance = measureCapacitance();
    lcd.clear();
    lcd.print("Capacitance: ");
    lcd.setCursor(0, 1);
    lcd.print(capacitance, 3);
    lcd.print(" uF");
    delay(2000);
    lcd.clear();
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Ready        ");
  }
}


#define LEDGREEN 2
#define LEDYELLOW 3
#define LEDRED 4
#define TRIGGER 5
#define ECHO 6
#define BUZZER 9

const float sound = 34300.0;
const float threshold1 = 30.0;
const float threshold2 = 20.0;
const float threshold3 = 10.0;

void turnoffLEDs(){
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDYELLOW, LOW);
}

void initiateTrigger(){
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
}

float calculateDistance(){
  unsigned long time = pulseIn(ECHO, HIGH);
  float distance = time * 0.000001 * sound / 2.0;
  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);

  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  turnoffLEDs();

}

void alerts(float distance){
  if (distance < threshold3){
    digitalWrite(LEDRED, HIGH);
    tone(BUZZER, 3000, 200);
  } else if (distance < threshold2){
    digitalWrite(LEDYELLOW, HIGH);
    tone(BUZZER, 2500, 200)
  } else if (distance < threshold1){
    digitalWrite(LEDGREEN, HIGH);
    tone(BUZZER, 2000, 200)
  }
}

void loop() {
  initiateTrigger();
  float distance = calculateDistance();
  turnoffLEDs();

}

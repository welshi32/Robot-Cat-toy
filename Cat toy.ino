#define SERVO_PIN 15
#define PIR 13
#define DEBUG true

#include "Servo.h"

int wait = 0;
int angle = 0;
bool toyActive = 0;

Servo toy;
void setup() {
  Serial.begin(9600);
  toy.attach(SERVO_PIN);
}

void loop() {
  if(digitalRead(PIR) == HIGH) {
    toyActive = 1;
  }
  else {
    delay(random(1000, 10000));
    toyActive = 0;
  }
  if(toyActive == 1) {
    toyActivate();
  }
}
void toyActivate() {
  wait = random(800, 4000);
  angle = random(-1, 181);
  if(DEBUG == true) {
    Serial.println("Angle: ");
    Serial.print(angle);
    Serial.print(", Delay:");
    Serial.print(wait);
  } 
  toy.write(angle);
  delay(wait);
}

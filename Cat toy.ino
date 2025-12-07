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
  pinMode(PIR, INPUT);      // IMPORTANT
  toy.attach(SERVO_PIN);
}

void loop() {

  toyActive = digitalRead(PIR);   // 1 or 0

  if (toyActive) {
    toyActivate();
  } else {
    toy.write(90);  // neutral or "off" position
    delay(50);      // tiny delay so loop doesn't spam
  }
}

void toyActivate() {
  wait = random(800, 4000);
  angle = random(0, 180);

  if (DEBUG) {
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Delay: ");
    Serial.println(wait);
  }

  toy.write(angle);
  delay(wait);
}
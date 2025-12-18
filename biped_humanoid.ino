#include <Servo.h>

Servo leftLeg;
Servo rightLeg;

#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
int distance;

void setup() {
  leftLeg.attach(5);
  rightLeg.attach(6);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  leftLeg.write(90);
  rightLeg.write(90);
}

void loop() {
  distance = getDistance();

  if (distance < 20) {
    stopWalking();
    delay(500);
    turnRobot();
  } else {
    walkForward();
  }
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void walkForward() {
  leftLeg.write(60);
  rightLeg.write(120);
  delay(300);

  leftLeg.write(120);
  rightLeg.write(60);
  delay(300);
}

void stopWalking() {
  leftLeg.write(90);
  rightLeg.write(90);
}

void turnRobot() {
  leftLeg.write(120);
  rightLeg.write(120);
  delay(400);
}

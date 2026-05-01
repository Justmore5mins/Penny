#include <Servo.h>

Servo SteeringMotor;

void setup() {
  SteeringMotor.attach(3);
  Serial.begin(115200);
}

void loop() {
  SteeringMotor.write(-1);
  delay(1500);
}

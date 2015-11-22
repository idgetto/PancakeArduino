#include <Servo.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <PancakePrinter.h>

PancakePrinter pp;

void setup() {
  Serial.begin(115200);
  pp.init();
  pp.listen();
}

void loop() {}

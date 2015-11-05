#include <Servo.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Gantry.h>
#include <PancakePrinter.h>

PancakePrinter pp;

void setup() {
  Serial.begin(9600);
  pp.init();
}

void loop() {
  pp.setTemperature(400);
  pp.extrudeOn();
  
  // make a square
  pp.moveTo(0, 100);
  pp.moveTo(100, 100);
  pp.moveTo(100, 0);  
  pp.moveTo(0, 0);
  
  pp.extrudeOff();
  pp.setTemperature(0);
}

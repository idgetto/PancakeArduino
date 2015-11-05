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
  pp.setTemperature(0);
  pp.moveTo(100, 50);
  delay(250);
  
  pp.setTemperature(300);
  pp.moveTo(0, 30);
  delay(250);
  
  pp.setTemperature(150);
  pp.moveTo(150, 120);  
  delay(250);
  
  pp.setTemperature(400);
  pp.moveTo(0,  0);
  delay(250);
}

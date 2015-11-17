#include <Servo.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <PancakePrinter.h>

PancakePrinter pp;

char NEW_LINE = '\n';
String DONE_STRING = "DONE";

  
void setup() {
  // start serial communication
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  // start up the printer
  pp.init();

  // listen for commands
  pp.readRecipe();

  pp.runRecipe();
}

void ack(String command) {
    Serial.println(command);
}

void loop() {
//  Serial.println("loop");
//  pp.setTemperature(0);
//  pp.extrudeOn();
//  
//  // make a square
//  pp.moveTo(0, 100);
//  pp.setTemperature(400);
//
//  pp.extrudeOff();
//  pp.moveTo(100, 100);
//    pp.setTemperature(0);
//
//  pp.extrudeOff();
//  pp.moveTo(100, 0);
//  pp.setTemperature(400);
//  
//  pp.extrudeOn();
//  pp.moveTo(0, 0);
  
//  pp.extrudeOn();
//  delay(1000);
//  pp.extrudeOff();
//  delay(1000);
}

void dots() {
  pp.setTemperature(Griddle::MAX_TEMPERATURE);
  for (int i = 0; i < 265; i += 50) {
    pp.moveTo(i, i);
    pp.extrudeOn();
    delay(500);
    pp.extrudeOff();
    delay(500);
  } 
}

void back_and_forth() {
  while (true) {
    pp.moveTo(100, 100);
    pp.moveTo(0, 0);
  }
}

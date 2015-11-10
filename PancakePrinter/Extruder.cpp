#include "Extruder.h"
#include <Arduino.h>

Extruder::Extruder(Adafruit_DCMotor *pumpMotor, 
                   Adafruit_DCMotor *solenoidMotor) :
                   _pumpMotor{pumpMotor},
                   _solenoidMotor{solenoidMotor} {
    Serial.println("Extruder");
}

void Extruder::extrudeOn(float speed) {
    Serial.println("Extrude On");
    openValve();
    runPump(speed);
}

void Extruder::extrudeOff() {
    Serial.println("Extrude Off");
    stopPump();
    closeValve();
}

void Extruder::runPump(int speed) {
    Serial.println("Pump On");
    _pumpMotor->setSpeed(128);
    _pumpMotor->run(FORWARD);
}

void Extruder::stopPump() {
    Serial.println("Pump Off");
    _pumpMotor->run(RELEASE);
}

void Extruder::openValve() {
    _solenoidMotor->setSpeed(255);
    _solenoidMotor->run(FORWARD);
}


void Extruder::closeValve() {
    _solenoidMotor->run(RELEASE);
}

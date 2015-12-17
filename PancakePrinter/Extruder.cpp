#include "Extruder.h"
#include <Arduino.h>

Extruder::Extruder(Adafruit_DCMotor *pumpMotor,
                   Adafruit_DCMotor *solenoidMotor) :
                   _pumpMotor{pumpMotor},
                   _solenoidMotor{solenoidMotor} {
}

void Extruder::extrudeOn(float speed) {
    openValve();
    runPump(speed);
    delay(850);
}

void Extruder::extrudeOff() {
    stopPump();
    closeValve();
    delay(500);
}

void Extruder::runPump(int speed) {
    _pumpMotor->setSpeed(255);
    _pumpMotor->run(FORWARD);
}

void Extruder::stopPump() {
    _pumpMotor->run(RELEASE);
}

void Extruder::openValve() {
    _solenoidMotor->setSpeed(255);
    _solenoidMotor->run(FORWARD);
}


void Extruder::closeValve() {
    _solenoidMotor->run(RELEASE);
}

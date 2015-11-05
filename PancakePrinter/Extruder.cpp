#include "Extruder.h"
#include <Arduino.h>

Extruder::Extruder(int pumpMotorShieldAddr, int pumpMotorPort, int solenoidPin) :
    _pumpMotorShieldAddr{pumpMotorShieldAddr},
    _motorShield{pumpMotorShieldAddr},
    _pumpMotorPort{pumpMotorPort},
    _solenoidPin{solenoidPin} {
    _pumpMotor = _motorShield.getMotor(_pumpMotorPort); 
}

void Extruder::extrudeOn(float speed) {
    openValve();
    _pumpMotor->setSpeed(speed);
    _pumpMotor->run(FORWARD);
}

void Extruder::extrudeOff() {
    _pumpMotor->run(RELEASE);
    closeValve();
}

void Extruder::openValve() {
    analogWrite(_solenoidPin, HIGH);
}

void Extruder::closeValve() {
    analogWrite(_solenoidPin, LOW);
}

void Extruder::_init() {
    _motorShield.begin();
    pinMode(_solenoidPin, OUTPUT);
}

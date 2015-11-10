#include "PancakePrinter.h"
#include <Arduino.h>

PancakePrinter::PancakePrinter() :
    _topMotorShield{0x61},
    _botMotorShield{0x60},
    _xStepper{_topMotorShield.getStepper(200, 1)},
    _yStepper{_topMotorShield.getStepper(200, 2)},
    _pumpMotor{_botMotorShield.getMotor(2)},
    _solenoidMotor{_botMotorShield.getMotor(4)},
    _griddle{PancakePrinter::GRIDDLE_PIN},
    _gantry{_xStepper, _yStepper},
    _extruder{_pumpMotor, _solenoidMotor} {
        Serial.println("PP::PP");
}

void PancakePrinter::init() {
    _topMotorShield.begin();
    _botMotorShield.begin();
    _griddle.init();
}

void PancakePrinter::moveTo(float x, float y) {
    _gantry.moveTo(x, y);
}

void PancakePrinter::setTemperature(float temp) {
    _griddle.setTemperature(temp);
}

void PancakePrinter::extrudeOn() {
    _extruder.extrudeOn();
}

void PancakePrinter::extrudeOff() {
    _extruder.extrudeOff();
}

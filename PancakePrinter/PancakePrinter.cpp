#include "PancakePrinter.h"

PancakePrinter::PancakePrinter() :
    _gantry{PancakePrinter::GANTRY_X_MOTOR_SHIELD_ADDR, 
            PancakePrinter::GANTRY_X_STEPPER_PORT,
            PancakePrinter::GANTRY_Y_MOTOR_SHIELD_ADDR,
            PancakePrinter::GANTRY_Y_STEPPER_PORT},
    _griddle{PancakePrinter::GRIDDLE_PIN},
    _extruder{PancakePrinter::EXTRUDER_MOTOR_SHIELD_ADDR,
              PancakePrinter::EXTRUDER_MOTOR_PORT,
              PancakePrinter::EXTRUDER_SOLENOID_PIN} {
}

void PancakePrinter::_init() {
    _gantry.init();
    _griddle.init();
    _extruder.init();
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

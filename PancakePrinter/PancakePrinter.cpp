#include "PancakePrinter.h"

PancakePrinter::PancakePrinter() :
    _gantry{0x60, 2, 0x61, 2},
    _griddle{9} {
}

void PancakePrinter::_init() {
    _gantry.init();
    _griddle.init();
    // extruder.init();
}

void PancakePrinter::moveTo(float x, float y) {
    _gantry.moveTo(x, y);
}

void PancakePrinter::setTemperature(float temp) {
    _griddle.setTemperature(temp);
}

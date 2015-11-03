#include "Gantry.h"

Gantry::Gantry( int xMotorShieldAddr, int xStepperPort,
                int yMotorShieldAddr, int yStepperPort) :
                    _xMotorShieldAddr{xMotorShieldAddr},
                    _xStepperPort{xStepperPort},
                    _yMotorShieldAddr{yMotorShieldAddr},
                    _yStepperPort{yStepperPort} { }

void Gantry::init() {
}

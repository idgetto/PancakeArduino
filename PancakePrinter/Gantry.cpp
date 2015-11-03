#include "Gantry.h"

Gantry::Gantry( int xMotorShieldAddr, int xStepperPort,
                int yMotorShieldAddr, int yStepperPort) :
                    _xMotorShieldAddr{xMotorShieldAddr},
                    _xStepperPort{xStepperPort},
                    _yMotorShieldAddr{yMotorShieldAddr},
                    _yStepperPort{yStepperPort},
                    _xMotorShield{_xMotorShieldAddr},
                    _yMotorShield{_yMotorShieldAddr} {
    _xStepper = _xMotorShield.getStepper(STEPS_PER_REV, _xStepperPort);
    _yStepper = _yMotorShield.getStepper(STEPS_PER_REV, _yStepperPort);
}

void Gantry::move(float x, float y, float speed) {
    assertInitialized();
}

void Gantry::_init() {
    _xMotorShield.begin();
    _yMotorShield.begin();
}

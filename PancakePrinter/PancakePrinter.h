#ifndef PANCAKE_PRINTER_H
#define PANCAKE_PRINTER_H

#include "Gantry.h"
#include "Griddle.h"
#include "Extruder.h"

class PancakePrinter : public Initializable {
    public:
        PancakePrinter();
        void moveTo(float x, float y);
        void setTemperature(float temp);
    protected:
        void _init();
    private:
        Gantry _gantry;
        Griddle _griddle;
        // Extruder _extruder;

        const int GANTRY_X_MOTOR_SHIELD_ADDR = 0x60;
        const int GANTRY_Y_MOTOR_SHIELD_ADDR = 0x60;
        const int GANTRY_X_STEPPER_PORT = 2;
        const int GANTRY_Y_STEPPER_PORT = 2;

        const int GRIDDLE_PIN = 9;
};

#endif

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
};

#endif

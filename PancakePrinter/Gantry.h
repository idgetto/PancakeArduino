/*
    The API used to control the position of the CNC Gantry
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GANTRY_H
#define GANTRY_H

#include <Arduino.h>

class Gantry {
    public:
        Gantry( int xMotorShieldAddr, int xStepperPort,
                int yMotorShieldAddr, int yStepperPort);
        void init();
        void move(float x, float y, float speed = Gantry::DEFAULT_SPEED);

    private:
        static const float DEFAULT_SPEED = 10;

        int _xMotorShieldAddr;
        int _yMotorShieldAddr;
        int _xStepperPort;
        int _yStepperPort;
};

#endif

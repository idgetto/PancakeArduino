/*
    The API used to control the position of the CNC Gantry
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GANTRY_H
#define GANTRY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

#include "Initializable.h"

class Gantry : public Initializable {
    public:
        Gantry( int xMotorShieldAddr, int xStepperPort,
                int yMotorShieldAddr, int yStepperPort);
        void move(float x, float y, float speed = Gantry::DEFAULT_SPEED);

    protected:
        void _init();

    private:
        static const float DEFAULT_SPEED = 10;
        static const unsigned STEPS_PER_REV = 200;

        int _xMotorShieldAddr;
        int _yMotorShieldAddr;
        int _xStepperPort;
        int _yStepperPort;

        Adafruit_MotorShield _xMotorShield;
        Adafruit_MotorShield _yMotorShield;
        Adafruit_StepperMotor *_xStepper;
        Adafruit_StepperMotor *_yStepper;
};

#endif

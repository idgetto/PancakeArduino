/*
    The API used to control the position of the CNC Gantry
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GANTRY_H
#define GANTRY_H

#define DEFAULT_GANTRY_SPEED 10
#define STEPS_PER_REV 200

#define DIST_PER_TOOTH 5.0f
#define NUM_PULLEY_TEETH 26
#define DIST_PER_REV ((NUM_PULLEY_TEETH) * (DIST_PER_TOOTH))
#define DIST_PER_STEP ((DIST_PER_REV) / (STEPS_PER_REV))

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

class Gantry {
    public:
        Gantry(Adafruit_StepperMotor *xStepper,
               Adafruit_StepperMotor *yStepper);
        void moveTo(float x, float y, float speed = DEFAULT_GANTRY_SPEED);

    protected:
        void _init();

    private:
        float _x;
        float _y;

        Adafruit_StepperMotor *_xStepper;
        Adafruit_StepperMotor *_yStepper;

        void moveLinear(int xSteps, int ySteps, float speed);
        int distToSteps(float dist);
        float stepsToDist(int steps);
        void xStep(int steps, int direction);
        void yStep(int steps, int direction);
        int getStepDirection(int steps); 
};

#endif

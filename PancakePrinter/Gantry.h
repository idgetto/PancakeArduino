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
#include <float.h>

class Gantry {
    public:
        Gantry(Adafruit_StepperMotor *xStepper,
               Adafruit_StepperMotor *yStepper);
        void moveTo(float x, float y, float speed = DEFAULT_SPEED);
        void calibrate();
        void release();

        static constexpr int STEPS_PER_REV = 200;

    protected:
        void _init();

    private:
        float _x;
        float _y;

        float _xLimit = FLT_MAX;
        float _yLimit = FLT_MAX;

        Adafruit_StepperMotor *_xStepper;
        Adafruit_StepperMotor *_yStepper;

        static constexpr int X_MAX_LIMIT_PIN = 2;
        static constexpr int Y_MAX_LIMIT_PIN = 5;
        static constexpr int X_MIN_LIMIT_PIN = 3;
        static constexpr int Y_MIN_LIMIT_PIN = 4;

        static constexpr int DEFAULT_SPEED = 100;
        static constexpr double DIST_PER_TOOTH = 5.0;
        static constexpr int NUM_PULLEY_TEETH_MINOR_AXIS = 26;
        static constexpr int NUM_PULLEY_TEETH_MAJOR_AXIS = 20;
        static constexpr double DIST_PER_REV_MINOR_AXIS = NUM_PULLEY_TEETH_MINOR_AXIS * DIST_PER_TOOTH;
        static constexpr double DIST_PER_REV_MAJOR_AXIS = NUM_PULLEY_TEETH_MAJOR_AXIS * DIST_PER_TOOTH;
        static constexpr double DIST_PER_STEP_MINOR_AXIS = DIST_PER_REV_MINOR_AXIS / STEPS_PER_REV;
        static constexpr double DIST_PER_STEP_MAJOR_AXIS = DIST_PER_REV_MAJOR_AXIS / STEPS_PER_REV;

        void moveLinear(int xSteps, int ySteps);
        int distToStepsMajorAxis(float dist);
        int distToStepsMinorAxis(float dist);
        float stepsToDistMajorAxis(int steps);
        float stepsToDistMinorAxis(int steps);
        void xStep(int steps = 1, int direction = FORWARD);
        void yStep(int steps = 1, int direction = FORWARD);
        int getStepDirection(int steps);
        float clamp(float val, float low, float high);
};

#endif

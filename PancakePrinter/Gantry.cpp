#include <math.h>

#include "Gantry.h"
#include <Arduino.h>

Gantry::Gantry(Adafruit_StepperMotor *xStepper,
               Adafruit_StepperMotor *yStepper) :
    _xStepper{xStepper},
    _yStepper{yStepper} {
        _xStepper->setSpeed(100);
        _yStepper->setSpeed(100);
}

void Gantry::moveTo(float x, float y, float speed) {
    float dx = x - _x;
    float dy = y - _y;
    int xSteps = distToStepsMajorAxis(dx);
    int ySteps = distToStepsMinorAxis(dy);

    moveLinear(dx, dy, speed);
    _x += stepsToDistMajorAxis(xSteps);
    _y += stepsToDistMinorAxis(ySteps);
}

void Gantry::moveLinear(int xSteps, int ySteps, float speed) {
    int xStepDirection = getStepDirection(xSteps);
    int yStepDirection = getStepDirection(ySteps);

    xSteps = abs(xSteps);
    ySteps = abs(ySteps);

    // don't need to calculate slope if one direction is zero
    if (xSteps == 0 || ySteps == 0) {
        xStep(xSteps, xStepDirection);
        yStep(ySteps, yStepDirection);
        return;
    }

    // find the slope of the linear path
    float slope = abs((float) ySteps / xSteps);

    // keep track of how many steps 
    // have been taken in each direction
    int xMoved, yMoved;
    xMoved = yMoved = 0;

    // accumulate partial y-steps as we
    // move one step at a time in the x-direction
    float yAccum = 0;

    while (xMoved < xSteps && yMoved < ySteps) {
        // add the number of partial steps we should take
        // in the y-direction for one step in the x-direction
        int xSteps = 1;
        yAccum += (xSteps * slope);

        // determine number of complete steps 
        // we can take in the y-direction
        int ySteps = floor(yAccum);
        yAccum -= ySteps;

        xStep(xSteps, xStepDirection);
        xMoved += xSteps;

        yStep(ySteps, yStepDirection);
        yMoved += ySteps;
    }
}

int Gantry::distToStepsMajorAxis(float dist) {
    return dist / DIST_PER_STEP_MAJOR_AXIS;
}

int Gantry::distToStepsMinorAxis(float dist) {
    return dist / DIST_PER_STEP_MINOR_AXIS;
}

float Gantry::stepsToDistMajorAxis(int steps) {
    return steps * DIST_PER_STEP_MAJOR_AXIS;
}

float Gantry::stepsToDistMinorAxis(int steps) {
    return steps * DIST_PER_STEP_MINOR_AXIS;
}

void Gantry::xStep(int steps, int direction) {
    _xStepper->step(steps, direction, DOUBLE);
}

void Gantry::yStep(int steps, int direction) {
    _yStepper->step(steps, direction, DOUBLE);
}

int Gantry::getStepDirection(int steps) {
    return steps > 0 ? FORWARD : BACKWARD;
}

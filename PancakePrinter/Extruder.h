/*
    The API to control the extrusion of pancake batter
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef EXTRUDER_H
#define EXTRUDER_H

#define DEFAULT_SPEED 125

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

class Extruder {
    public:
        Extruder(Adafruit_DCMotor *pumpMotor, 
                 Adafruit_DCMotor *solenoidMotor);
        void extrudeOn(float speed = DEFAULT_SPEED);
        void extrudeOff();

    private:
        Adafruit_DCMotor *_pumpMotor;
        Adafruit_DCMotor *_solenoidMotor;

        void openValve();
        void closeValve();
        void runPump(int speed);
        void stopPump();
};

#endif

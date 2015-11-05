/*
    The API to control the extrusion of pancake batter
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef EXTRUDER_H
#define EXTRUDER_H

#define DEFAULT_SPEED 10

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include "Initializable.h"

class Extruder : public Initializable {
    public:
        Extruder(int pumpMotorShieldAddr, int pumpMotorPort, int solenoidPin);
        void extrudeOn(float speed = DEFAULT_SPEED);
        void extrudeOff();

    protected:
        void _init();

    private:
        int _pumpMotorShieldAddr;
        Adafruit_MotorShield _motorShield;
        int _pumpMotorPort;
        Adafruit_DCMotor *_pumpMotor;

        int _solenoidPin;

        void openValve();
        void closeValve();
};

#endif

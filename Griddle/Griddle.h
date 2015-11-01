/*
    The API used to control the Griddle's heat
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GRIDDLE_H
#define GRIDDLE_H

#include <Arduino.h>
#include <Servo.h>

class Griddle {
    public:
        void attach(uint8_t themostatPin);
        void setTemperature(unsigned temp);

        static const unsigned MIN_TEMPERATURE = 0;
        static const unsigned MAX_TEMPERATURE = 400;
        static const unsigned MIN_DEGREES = 0;
        static const unsigned MAX_DEGREES = 170;

    private:
        uint8_t _thermostatPin;
        Servo _thermostatServo;

        int temperatureToDegrees(float temp);
};

#endif

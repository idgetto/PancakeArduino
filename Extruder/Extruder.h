/*
    The API to control the extrusion of pancake batter
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef EXTRUDER_H
#define EXTRUDER_H

class Extruder {
    public:
        Extruder(int pumpPin, int solenoidPin);
        void extrude(float speed = DEFAULT_SPEED);
        void stop();

    private:
        const float DEFAULT_SPEED = 10;

        int _pumpPin;
        int _solenoidPin;
};

#endif

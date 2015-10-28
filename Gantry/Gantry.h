/*
    The API used to control the position of the CNC Gantry
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GANTRY_H
#define GANTRY_H

class Gantry {
    public:
        Gantry(int pinX, int pinY);
        void move(float x, float y, float speed = DEFAULT_SPEED);

    private:
        const float DEFAULT_SPEED = 10;

        int _pinX;
        int _pinY;
};

#endif

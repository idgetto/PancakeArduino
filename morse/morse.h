/*
    morse.h - The morse code example library from the Arduino documentation.
*/

#ifndef MORSE_H
#define MORSE_H

#include "Arduino.h"

class morse {
    public:
        morse(int pin);
        void dot();
        void dash();
    private:
        int _pin;
};

#endif

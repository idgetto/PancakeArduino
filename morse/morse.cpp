#include "Arduino.h"
#include "morse.h"

morse::morse(int pin) 
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void morse::dot()
{
    analogWrite(_pin, HIGH);
    delay(250);
    analogWrite(_pin, LOW);
    delay(250);
}

void morse::dash()
{
    analogWrite(_pin, HIGH);
    delay(1000);
    analogWrite(_pin, LOW);
    delay(250);
}

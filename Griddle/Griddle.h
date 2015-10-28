/*
    The API used to control the Griddle's heat
    Author: Isaac Getto
    Date: 10/27/15
*/

#ifndef GRIDDLE_H
#define GRIDDLE_H

class Griddle {
    public:
        Griddle(int thermostatPin);
        void setTemperature(float temp);

    private:
        int _thermostatPin;
};

#endif

#include "Griddle.h"

void Griddle::attach(uint8_t thermostatPin) {
    _thermostatPin = thermostatPin;
    _thermostatServo.attach(_thermostatPin);
}

void Griddle::setTemperature(unsigned temp) {
    int degrees = temperatureToDegrees(temp);
    _thermostatServo.write(degrees);
}

int Griddle::temperatureToDegrees(float temp) {
    int degrees = map(temp, 
               Griddle::MIN_TEMPERATURE, 
               Griddle::MAX_TEMPERATURE, 
               Griddle::MAX_DEGREES, 
               Griddle::MIN_DEGREES);
    return degrees;
}

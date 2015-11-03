#include "Griddle.h"

Griddle::Griddle(uint8_t thermostatPin) {
    _thermostatPin = thermostatPin;
}

void Griddle::setTemperature(unsigned temp) {
    assertInitialized();
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

void Griddle::_init() {
    _thermostatServo.attach(_thermostatPin);
}

#include "Griddle.h"

Griddle::Griddle(int thermostatPin) : _thermostatPin{thermostatPin} {
}

void Griddle::setTemperature(float temp) {
    int degrees = temperatureToDegrees(temp);
    _thermostatServo.write(degrees);
    delay(100);
}

int Griddle::temperatureToDegrees(float temp) {
    int degrees = map(temp, 
               Griddle::MIN_TEMPERATURE, 
               Griddle::MAX_TEMPERATURE, 
               Griddle::MAX_DEGREES, 
               Griddle::MIN_DEGREES);
    return degrees;
}

void Griddle::init() {
    _thermostatServo.attach(_thermostatPin);
}

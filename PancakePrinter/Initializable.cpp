#include <stdlib.h>
#include <Arduino.h>

#include "Initializable.h"

void Initializable::init() {
    if (_initialized) {
        Serial.println("already initialized");
        exit(1);
    }

    _init();
    _initialized = true;
}

void Initializable::assertInitialized() {
    if (!_initialized) {
        Serial.println("not yet initialized");
        exit(1);
    }
}

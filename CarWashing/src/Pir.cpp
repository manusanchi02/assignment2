#include "Pir.h"
#include "Arduino.h"

Pir::Pir(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Pir::isDetected() {
    return digitalRead(pin) == HIGH;
}
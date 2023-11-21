#include "include/Led.h"
#include <Arduino.h>

Led::Led(int pin) {
    this->pin = pin;
    this->state = false;
    pinMode(pin, OUTPUT);
}

Led::switchOn() {
    pinMode(pin, HIGH);
    this->state = true;
}

Led::switchOff() {
    pinMode(pin, LOW);
    this->state = false;
}

Led::isOn() {
    return this->state;
}
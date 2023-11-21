#include"Led.h"
#include <Arduino.h>

Led::Led(int pin) {
    this->pin = pin;
    this->state = false;
    pinMode(pin, OUTPUT);
}

void Led::switchOn() {
    pinMode(pin, HIGH);
    this->state = true;
}

void Led::switchOff() {
    pinMode(pin, LOW);
    this->state = false;
}

bool Led::isOn() {
    return this->state;
}
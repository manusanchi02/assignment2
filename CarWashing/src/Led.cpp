#include "Led.h"
#include <Arduino.h>

Led::Led(int pin)
{
    this->pin = pin;
    this->state = false;
    pinMode(pin, OUTPUT);
}

void Led::switchOn()
{
    if(!this->isOn()) {
        digitalWrite(pin, HIGH);
        this->state = true;
    }
}

void Led::switchOff()
{
    if(this->isOn()) {
        digitalWrite(pin, LOW);
        this->state = false;
    }
}

bool Led::isOn()
{
    return this->state;
}
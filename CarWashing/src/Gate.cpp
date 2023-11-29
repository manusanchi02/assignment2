#include "Gate.h"
#include <Arduino.h>

Gate::Gate(int pin, int open, int close)
{
    this->pin = pin;
    this->open = open;
    this->close = close;
    this->state = false;
    this->pos = 0;
    this->servo.attach(pin);
    this->servo.write(pos);
}

void Gate::setOpen()
{
    for(this->pos; this->pos <= this->open; pos++)
    {
        this->servo.write(pos);
        Serial.println("aprendo");
        Serial.println(pos);
    }
    this->state = true;
}

void Gate::setClose()
{
    for(this->pos; this->pos >= this->close; pos--)
    {
        this->servo.write(pos);
        Serial.println("chiudendo");
        Serial.println(pos);
    }
    this->state = false;
}

bool Gate::isOpen()
{
    return this->state;
}
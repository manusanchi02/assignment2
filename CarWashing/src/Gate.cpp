#include "Gate.h"
#include <Arduino.h>

Gate::Gate(int pin, int open, int close)
{
    this->pin = pin;
    this->open = open;
    this->close = close;
    this->state = false;
    this->pos = 0;
    this->servo.write(pos);
    //delay(5);
}

void Gate::setOpen()
{
    if(!this->state){
        this->servo.attach(pin);
        for(this->pos = 0; this->pos <= this->open; pos++)
        {
            this->servo.write(pos);
            Serial.println("aprendo");
            //Serial.print(pos);
            Serial.print(this->servo.read());
        }
        this->state = true;
        this->servo.detach();
    }
}

void Gate::setClose()
{
    Serial.println("devo chiudere");
    if(this->state) {
        this->servo.attach(pin);
        for(this->pos = this->open; this->pos >= this->close; pos--)
        {
            this->servo.write(pos);
            Serial.println("chiudendo ");
            Serial.print(pos);
        }
        this->state = false;
        this->servo.detach();
    }
}

bool Gate::isOpen()
{
    return this->state;
}
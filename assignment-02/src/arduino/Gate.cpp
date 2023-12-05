#include "Gate.h"
#include <Arduino.h>
#include "GlobalVariables.h"
#define DELTA 1 // 1 degree


Gate::Gate(int pin, int open, int close)
{
    this->pin = pin;
    this->open = open;
    this->close = close;
    this->pos = 0;
}

void Gate::setOpen()
{
    this->pos = 0; // reset the position to 0
    if(!gateState) {
        this->servo.attach(pin);
        for(int i = 0; i < this->open; i++) {
            this->pos+=DELTA;
            this->servo.write(pos);
            delay(6); // small delay to permit the servo to reach the position
        }
        gateState = true;
        this->servo.detach();
    }
}

void Gate::setClose()
{
    this->pos = 90; // reset the position to 90
    if(gateState) {
        this->servo.attach(pin);
        for(int a = 0; a < this->open; a++) {
            this->pos-=DELTA;
            this->servo.write(pos);
            delay(6); // small delay to permit the servo to reach the position
        }
        gateState = false;
        this->servo.detach();
    }
}

bool Gate::isOpen()
{
    return gateState;
}
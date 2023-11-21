#include "include/Gate.h"

Gate::Gate(int pin,int open,int close) {
    this->pin = pin;
    this->open = open;
    this->close = close;
    this->state = false;
    this->servo.attach(pin);
}

void Gate::setOpen() {
    this->servo.write(this->open);
    this->state = true;
}

void Gate::setClose() {
    this->servo.write(this->close);
    this->state = false;
}

bool Gate::isOpen() {
    return this->state;
}
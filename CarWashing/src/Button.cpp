#include"Button.h"
#define FIXAMOUNT 300

long previousTime;

Button::Button(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool resolveBouncing() {
    return (millis() - previousTime > FIXAMOUNT);
}

bool Button::isPressed() {
    return resolveBouncing() && digitalRead(pin) == HIGH;
}
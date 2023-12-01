#include "Button.h"
#include <Arduino.h>
#define FIXAMOUNT 50

long previousTime;

Button::Button(int pin)
{
    this->pin = pin;
    previousTime = millis();
    pinMode(pin, INPUT);
}

bool resolveBouncing()
{
    if (millis() - previousTime > FIXAMOUNT)
    {
        previousTime = millis();
        return true;
    }
    return false;
}

bool Button::isPressed()
{
    return resolveBouncing() && digitalRead(pin) == HIGH;
}
#include "Pir.h"
#include "Arduino.h"

#define CALIBRATION_TIME_SEC 2

Pir::Pir(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
    for (int i = 0; i < CALIBRATION_TIME_SEC; i++)
    {
        delay(1000);
    }
}

bool Pir::isDetected()
{
    return digitalRead(pin) == HIGH;
}
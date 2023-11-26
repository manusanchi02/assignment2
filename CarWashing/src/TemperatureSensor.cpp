#include "TemperatureSensor.h"
#include "Arduino.h"

TemperatureSensor::TemperatureSensor(int pin)
{
    this->pin = pin;
}

float TemperatureSensor::getTemperature()
{
    int value = analogRead(pin);
    double value_in_mV = value * 4.8876;
    double value_in_Celsius = value_in_mV * 0.1;
    return value_in_Celsius;
}

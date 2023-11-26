#include "Sonar.h"
#include <Arduino.h>

const float temperature = 20;
const float velocitaSuono = 331.45 + 0.62 * temperature;

Sonar::Sonar(int echoPinIn, int trigPinOut)
{
    this->echoPinIn = echoPinIn;
    this->trigPinOut = trigPinOut;
    Serial.begin(9600);
    pinMode(echoPinIn, INPUT);
    pinMode(trigPinOut, OUTPUT);
}

float Sonar::getDistance()
{
    digitalWrite(trigPinOut, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPinOut, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPinOut, LOW);
    float tUS = pulseIn(echoPinIn, HIGH);
    float t = tUS / 2000000.0;
    float d = t * velocitaSuono;
    return d;
}
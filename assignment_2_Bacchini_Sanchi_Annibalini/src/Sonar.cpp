#include "include/Sonar.h"
#include <Arduino.h>

Sonar::Sonar(int echoPinIn, int trigPinOut, float velocitaSuono) {
    this->pinIn = echoPinIn;
    this->pinOut = trigPinOut;
    this->velocitaSuono = velocitaSuono;
    Serial.begin(115200);
    pinMode(echoPinIn, INPUT);
    pinMode(trigPinOut, OUTPUT);
}

float Sonar::getDistance() {
    digitalWrite(trigPinOut, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPinOut, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPinOut, LOW);
    float tUS = pulseIn(echoPinIn, HIGH);
    float t = tUS / 2000000.0;
    float d = t*velocitaSuono;
    return d;
}
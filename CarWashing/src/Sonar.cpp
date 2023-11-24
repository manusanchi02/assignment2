#include"Sonar.h"
#include <Arduino.h>

Sonar::Sonar(int echoPinIn, int trigPinOut, float velocitaSuono) {
    this->echoPinIn = echoPinIn;
    this->trigPinOut = trigPinOut;
    this->velocitaSuono = velocitaSuono;
    Serial.begin(9600);
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
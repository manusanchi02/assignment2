#include "Gate.h"
#include <Arduino.h>
#include "GlobalVariables.h"
#define DELTA 1


Gate::Gate(int pin, int open, int close)
{
    this->pin = pin;
    this->open = open;
    this->close = close;
    this->pos = 0;
}

void Gate::setOpen()
{
    Serial.println("devo aprire");
    Serial.println(gateState);
    if(!gateState) {
        this->servo.attach(pin);
        for(int i = 0; i < this->open; i++) {
            this->pos+=DELTA;
            this->servo.write(pos);
            Serial.println(pos);
        }
        gateState = true;
        this->servo.detach();
    }
    /*if(!this->state){
        this->servo.attach(pin);
        Serial.print(this->servo.read());
        for(int i = 0; i < this->open; i++)
        {
            pos+=DELTA;
            this->servo.write(pos);
            Serial.println("aprendo");
            //Serial.print(pos);
            Serial.print(this->servo.read());
        }
        /*if(pos < this->open) {
            pos+=DELTA;
            this->servo.write(pos);
            Serial.println("aprendo");
            Serial.print(this->servo.read());
        } else {
            this->state = true;
            this->servo.detach();
        }
    }*/
}

void Gate::setClose()
{
    Serial.println("devo chiudere");
    Serial.println(gateState);
    if(gateState) {
        Serial.println("entrato");
        this->servo.attach(pin);
        Serial.println("attaccato");
        for(int a = 0; a < this->open; a++) {
            Serial.println("entrato nel for");
            this->pos-=DELTA;
            this->servo.write(pos);
            Serial.println(pos);
        }
        Serial.println("uscito dal for");
        gateState = false;
        this->servo.detach();
    }

/*
    Serial.println("devo chiudere");
    if(this->state) {
        this->servo.attach(pin);
        for(int i = 0; i < this->open; i++)
        {
            pos-=DELTA;
            this->servo.write(pos);
            Serial.println("aprendo");
            //Serial.print(pos);
            Serial.print(this->servo.read());
        }
        this->servo.write(this->close);
        this->state = false;
        Serial.println("La distanza è: ");
        Serial.print(this->servo.read());
        this->servo.detach();
    }*/
}

bool Gate::isOpen()
{
    return gateState;
}
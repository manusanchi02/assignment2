#include "WashBlinkLed.h"
#define PERIOD 60

int counter;

WashBlinkLed::WashBlinkLed(int pin) {
    this->pin = pin;
}

void WashBlinkLed::init(int period) {
    led = new Led(this->pin);
    Task::init(period);
    state = OFF;
}

void WashBlinkLed::tick() {
    if(washing && counter < PERIOD) {
        switch (state){
        case OFF:
            led->switchOn();
            state = ON;
            break;
        case ON:
            led->switchOff();
            state = OFF;
            break;
        }
    } else {
        washing = false;
        leaving = true;
    }
}
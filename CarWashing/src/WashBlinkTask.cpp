#include "WashBlinkLed.h"
#define PERIOD 60

int counter;

WashBlinkLed::WashBlinkLed(int pin) {
    this->pin = pin;
    counter = 0;
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
        counter = 0;
        washing = false;
        leaving = true;
    }
}
#include "WashBlinkTask.h"
#define PERIOD 60

WashBlinkTask::WashBlinkTask(int pin)
{
    this->pin = pin;
    counter = 0;
}

void WashBlinkTask::init(int period)
{
    led = new Led(this->pin);
    Task::init(period);
    state = OFF;
}

void WashBlinkTask::tick()
{
    Serial.println("f");
    if (washing)
    {
        Serial.print("Washing ");
        switch (state)
        {
        case OFF:
            led->switchOn();
            state = ON;
            break;
        case ON:
            led->switchOff();
            state = OFF;
            break;
        }
        counter += myPeriod;
    }
    if (counter >= N4 )
    {
        counter = 0;
        washing = false;
        leaving = true;
    }
}
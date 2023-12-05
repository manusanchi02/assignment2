#include "WashBlinkTask.h"

WashBlinkTask::WashBlinkTask(int pin)
{
    this->pin = pin;
}

void WashBlinkTask::init(int period)
{
    led = new Led(this->pin);
    Task::init(period);
    state = OFF;
}

void WashBlinkTask::tick()
{
    if (washing && !error)
    {
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
    }
}
#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin)
{
    this->pin = pin;
}

void BlinkTask::init(int period)
{
    led = new Led(pin);
    state = OFF;
    Task::init(period);
}

void BlinkTask::tick()
{
    if (moving)
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
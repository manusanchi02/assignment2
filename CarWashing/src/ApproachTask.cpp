#include "ApproachTask.h"

ApproachTask ::ApproachTask(int pinTrigger, int pinEcho)
{
    this->pinTrigger = pinTrigger;
    this->pinEcho = pinEcho;
    this->counter = 0;
}

void ApproachTask ::init(int period)
{
    this->period = period;
    sonar = new Sonar(pinTrigger, pinEcho);
    Task::init(period);
}

void ApproachTask ::tick()
{
    if (moving && counter < N2)
    {
        Serial.println("Approaching");
        if (sonar->getDistance() < minDist)
        {
            counter += period;
        }
        else
        {
            counter = 0;
        }
    }
    else
    {
        moving = false;
        ready = true;
        counter = 0;
    }
}
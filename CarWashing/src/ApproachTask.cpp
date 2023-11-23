#include "ApproachTask.h"

ApproachTask ::ApproachTask(int pinTrigger, int pinEcho, float velocitaSuono)
{
    this->pinTrigger = pinTrigger;
    this->pinEcho = pinEcho;
    this->velocitaSuono = velocitaSuono;
    this->counter = 0;
}

void ApproachTask ::init(int period)
{
    this->period = period;
    sonar = new Sonar(pinTrigger, pinEcho, velocitaSuono);
    Task::init(period);
}

void ApproachTask ::tick()
{
    if (moving && counter < N2)
    {
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
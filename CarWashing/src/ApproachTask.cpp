#include "ApproachTask.h"

ApproachTask ::ApproachTask(int pinTrigger, int pinEcho, double minDist)
{
    this->pinTrigger = pinTrigger;
    this->pinEcho = pinEcho;
    this->counter = 0;
    this->minDist = minDist;
}

void ApproachTask ::init(int period)
{
    sonar = new Sonar(pinEcho, pinTrigger);
    Task::init(period);
}

void ApproachTask ::tick()
{
    if (moving)
    {
        if (sonar->getDistance() < minDist)
        {
            counter += myPeriod;
        }
        else
        {
            counter = 0;
        }
    }
    if(counter >= N2)
    {
        isNear = true;
        counter = 0;
    }
}
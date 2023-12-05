#include "ApproachTask.h"

ApproachTask ::ApproachTask(int pinTrigger, int pinEcho)
{
    this->pinTrigger = pinTrigger;
    this->pinEcho = pinEcho;
    this->counter = 0; // counter for the time spent in this state
}

void ApproachTask ::init(int period)
{
    sonar = new Sonar(pinEcho, pinTrigger);
    Task::init(period);
}

void ApproachTask ::tick()
{
    // condition to check if we are in this state
    if (moving && !error)
    {
        if (sonar->getDistance() < MINDIST)
        {
            counter += myPeriod;
        }
        else
        {
            counter = 0;
        }
    }
    // exit condition
    if(counter >= N2)
    {
        isNear = true;
        counter = 0;
    }
}
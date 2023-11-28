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
    sonar = new Sonar(pinTrigger, pinEcho);
    Task::init(period);
}

void ApproachTask ::tick()
{
    Serial.println("d");
    if (moving)
    {
        Serial.println("Approaching");
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
        moving = false;
        ready = true;
        counter = 0;
    }
}
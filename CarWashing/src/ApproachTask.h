#ifndef __APPROACHTASK__
#define __APPROACHTASK__
#include "Task.h"
#include "Sonar.h"

class ApproachTask : public Task
{
public:
    ApproachTask(int pinTrigger, int pinEcho);
    void init(int period);
    void tick();

protected:
    int pinTrigger;
    int pinEcho;
    int counter;
    Sonar *sonar;
};

#endif
#ifndef __APPROACHTASK__
#define __APPROACHTASK__
#include "Task.h"
#include "Sonar.h"

class ApproachTask : public Task
{
public:
    ApproachTask(int pinTrigger, int pinEcho, float velocitaSuono);
    void init(int period);
    void tick();

protected:
    int pinTrigger;
    int pinEcho;
    float velocitaSuono;
    int counter;
    int period;
    Sonar *sonar;
};

#endif
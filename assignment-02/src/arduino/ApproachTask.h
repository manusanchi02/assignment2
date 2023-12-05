#ifndef __APPROACHTASK__
#define __APPROACHTASK__
#include "Task.h"
#include "Sonar.h"

class ApproachTask : public Task
{
public:
    /**
     * Constructor for the ApproachTask class.
     * @param pinTrigger The pin number for the trigger pin of the sonar.
     * @param pinEcho The pin number for the echo pin of the sonar.
    */
    ApproachTask(int pinTrigger, int pinEcho);
    /**
     * Init method.
    */
    void init(int period);
    /**
     * Tick method.
    */
    void tick();

protected:
    int pinTrigger;
    int pinEcho;
    int counter;
    Sonar *sonar;
};

#endif
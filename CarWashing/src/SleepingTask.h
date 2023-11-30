#ifndef __SLEEPIINGTASK__
#define __SLEEPINGTASK__
#include "Task.h"
#include <avr/sleep.h>
#include <avr/power.h>

class SleepingTask : public Task
{
public:
    /**
     * Class constructor.
     */
    SleepingTask(int pirPin);
    /**
     * Init method.
     * @param period the period of the task.
     */
    void init(int period);
    /**
     * Tick method.
     */
    void tick();

protected:
    int pirPin;
};

#endif
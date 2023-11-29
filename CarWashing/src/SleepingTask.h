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
     */
    void init();
    /**
     * Tick method.
     */
    void tick();

protected:
    int pirPin;
};

#endif
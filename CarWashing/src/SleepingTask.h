#ifndef __SLEEPIINGTASK__
#define __SLEEPINGTASK__
#include "Task.h"

class SleepingTask : public Task
{
public:
    /**
     * Class constructor.
     */
    SleepingTask();
    /**
     * Init method.
     */
    void init();
    /**
     * Tick method.
     */
    void tick();

protected:
    int counter;
};

#endif
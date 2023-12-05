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
     * @param pirPin the pin of the PIR sensor.
     * @param ledpin the pin of the led.
     */
    SleepingTask(int pirPin, int ledpin);
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
    int ledpin;
};

#endif
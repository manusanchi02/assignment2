#ifndef __WELCOMETASK__
#define __WELCOMETASK__
#include "Task.h"
#include "Led.h"
#include "LcdMonitor.h"

class WelcomeTask : public Task
{
public:
    /**
     * Class constructor:
     * @param pin number of the led pin
     */
    WelcomeTask(int pin, int rows, int columns);
    /**
     * Init method.
     * @param period task period
     * @param rows number of lcd rows
     * @param columns number of lcd columns
     */
    void init(int period);
    /**
     * Tick method.
     */
    void tick();

protected:
    int pin;
    int rows;
    int columns;
    int counter;
    int period;
    Led *led;
    LcdMonitor *lcd;
};

#endif
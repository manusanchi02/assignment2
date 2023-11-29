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
    Led *led;
    LcdMonitor *lcd;
};

#endif
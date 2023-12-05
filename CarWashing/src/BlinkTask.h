#ifndef __BLINKTASK__
#define __BLINKTASK__
#include "Task.h"
#include "Led.h"

class BlinkTask : public Task
{
public:
    /**
     * Constructor for the BlinkTask class.
     * @param pin the pin where the led is connected.
    */
    BlinkTask(int pin);
    /**
     * Init method.
    */
    void init(int period);
    /**
     * Tick method.
    */
    void tick();

protected:
    int pin;
    Led *led;
    enum
    {
        ON,
        OFF
    } state;
};
#endif
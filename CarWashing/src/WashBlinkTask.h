#ifndef __WASHBLINKTASK__
#define __WASHBLINKTASK__
#include "Task.h"
#include "Led.h"

class WashBlinkTask : public Task
{
public:
    /**
     * Class constructor.
     * @param pin number of pin where the led is connect.
     */
    WashBlinkTask(int pin);
    /**
     * Init method.
     * @param period
     */
    void init(int period);
    /**
     * Tick method.
     */
    void tick();

protected:
    int pin;
    int counter;
    Led *led;
    enum
    {
        ON,
        OFF
    } state;
};

#endif
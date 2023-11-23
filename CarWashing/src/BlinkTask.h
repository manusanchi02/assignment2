#ifndef __BLINKTASK__
#define __BLINKTASK__
#include "Task.h"
#include "Led.h"

class BlinkTask : public Task
{
public:
    BlinkTask(int pin);
    void init(int period);
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
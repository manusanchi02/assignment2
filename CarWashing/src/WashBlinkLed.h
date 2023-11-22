#ifndef __WASHBLINKLED__
#define __WASHBLINKLED__
#include "Task.h"
#include "Led.h"

class WashBlinkLed : public Task {
    public:
        /**
         * Class constructor.
         * @param pin number of pin where the led is connect.
        */
        WashBlinkLed(int pin);
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
        Led* led;
        enum { ON, OFF} state;
};

#endif
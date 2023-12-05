#ifndef __CLOSINGTASK__
#define __CLOSINGTASK__
#include "Task.h"
#include "Gate.h"
#include "Led.h"

class ClosingTask : public Task
{
public:
    /**
     * Class constructor:
     * @param gatePin number of the gate pin
     * @param gateOpen number of angular degrees to open the gate
     * @param gateClose number of angular degrees to close the gate
     * @param ledPin number of the pin where the led is connected
     */
    ClosingTask(int gatePin, int gateOpen, int gateClose, int ledPin);
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
    int gatePin;
    int gateOpen;
    int gateClose;
    int ledPin;
    Gate *gate;
    Led *led;
};

#endif
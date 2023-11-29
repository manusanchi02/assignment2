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
     * @param echoPin number of the echo pin
     * @param trigPin number of the trig pin
     * @param maxDistance max distance to start closing
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
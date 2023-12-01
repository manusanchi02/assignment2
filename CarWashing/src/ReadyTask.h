#ifndef __READYTASK__
#define __READYETASK__
#include "Task.h"
#include "Led.h"
#include "Gate.h"
#include "Sonar.h"
#include "LcdMonitor.h"

class ReadyTask : public Task
{
public:
    /**
     * Class constructor:
     * @param ledPin number of the led pin
     * @param gatePin number of the gate pin
     * @param echoPin number of the echo pin
     * @param trigPin number of the trig pin
     * @param minDistance minimum distance to start washing
     */
    ReadyTask(int ledPin, int gatePin, int gateOpen, int gateClose, int rows, int columns, int buttonPin);
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
    int ledPin;
    int gatePin;
    int rows;
    int columns;
    int buttonPin;
    int gateOpen;
    int gateClose;
    Led *led;
    Gate *gate;
    LcdMonitor *lcd;
};

#endif
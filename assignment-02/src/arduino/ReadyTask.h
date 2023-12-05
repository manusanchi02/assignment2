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
     * Class constructor.
     * @param ledPin number of the led pin
     * @param gatePin number of the gate pin
     * @param gateOpen number of angular degrees to open the gate
     * @param gateClose number of angular degrees to close the gate
     * @param rows number of lcd rows
     * @param columns number of lcd columns
     * @param buttonPin number of the button pin
     *
     */
    ReadyTask(int ledPin, int gatePin, int gateOpen, int gateClose, int rows, int columns, int buttonPin);
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
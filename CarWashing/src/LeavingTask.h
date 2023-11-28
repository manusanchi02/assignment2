#ifndef __LEAVINGTASK__
#define __LEAVINGTASK__
#include <Arduino.h>
#include "Task.h"
#include "Led.h"
#include "LcdMonitor.h"
#include "Gate.h"
#include "Sonar.h"

class LeavingTask : public Task
{
public:
    /**
     * Class constructor.
     * @param ledPin1 number of the first led pin
     * @param ledPin2 number of the second led pin
     * @param rows number of lcd rows
     * @param column number of lcd columns
     * @param gatePin number of the gate pin
     */
    LeavingTask(int ledPin1, int ledPin2, int rows, int column, int gatePin, int echoPinIn, int trigPinOut);
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
    int ledPin1;
    int ledPin2;
    int rows;
    int column;
    int gatePin;
    int echoPinIn;
    int trigPinOut;
    int counter;
    Led *led1;
    Led *led2;
    LcdMonitor *lcd;
    Gate *gate;
    Sonar *distanceSensor;
};

#endif
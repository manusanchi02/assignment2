#ifndef __MOVINGTASK__
#define __MOVINGTASK__
#include "Task.h"
#include "LcdMonitor.h"
#include "Gate.h"

class MovingTask : public Task
{
public:
    /**
     * Class constructor.
     * @param rows number of lcd rows
     * @param columns number of lcd columns
     * @param pinGate number of the gate pin
     * @param open number of angular degrees to open the gate
     * @param close number of angular degrees to close the gate
     */
    MovingTask(int rows, int columns, int pinGate, int open, int close);
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
    int rows;
    int columns;
    int pinGate;
    int open;
    int close;
    LcdMonitor *lcd;
    Gate *gate;
};
#endif
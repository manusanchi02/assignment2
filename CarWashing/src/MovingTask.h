#ifndef __MOVINGTASK__
#define __MOVINGTASK__
#include "Task.h"
#include "LcdMonitor.h"
#include "Gate.h"

class MovingTask : public Task
{
public:
    MovingTask(int pinLcd, int rows, int columns, int pinGate, int open, int close);
    void init(int period);
    void tick();

protected:
    int pinLcd;
    int rows;
    int columns;
    int pinGate;
    int open;
    int close;
    LcdMonitor *lcd;
    Gate *gate;
};
#endif
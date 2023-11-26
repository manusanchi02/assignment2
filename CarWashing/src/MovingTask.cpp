#include "MovingTask.h"

MovingTask ::MovingTask(int pinLcd, int rows, int columns, int pinGate, int open, int close)
{
    this->pinLcd = pinLcd;
    this->rows = rows;
    this->columns = columns;
    this->pinGate = pinGate;
    this->open = open;
    this->close = close;
}

void MovingTask ::init(int period)
{
    lcd = new LcdMonitor(rows, columns);
    gate = new Gate(pinGate, open, close);
    Task::init(period);
}

/**
 * isNear is a boolean variable that is set to true by the ApproachingTask when the car is near the washing area.
 */
void MovingTask ::tick()
{
    if (moving && !isNear)
    {
        lcd->setAndPrint("Proceed to the Washing Area", 1, 0);
        gate->setOpen();
    }
    else
    {
        moving = false;
        ready = true;
    }
}
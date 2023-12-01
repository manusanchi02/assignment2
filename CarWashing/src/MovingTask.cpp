#include "MovingTask.h"

MovingTask ::MovingTask(int rows, int columns, int pinGate, int open, int close)
{
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
    if (moving && !isNear && !error)
    {
        lcd->clean();
        lcd->setAndPrint("Proceed to the", 0, 0);
        lcd->setAndPrint("Washing Area", 0, 1);
        gate->setOpen();
    }
    if (moving && isNear && !error)
    {
        isNear = false;
        moving = false;
        ready = true;
    }
}
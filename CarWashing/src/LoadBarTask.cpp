#include "LoadBarTask.h"
#define BARCHAR "#"
LoadBarTask ::LoadBarTask(int rows, int column)
{
    this->rows = rows;
    this->column = column;
    counter = 0;
    bar = 0;
}

void LoadBarTask ::init(int period)
{
    lcd = new LcdMonitor(this->rows, this->column);
    Task::init(period);
}

void LoadBarTask ::tick()
{
    if (washing && !error)
    {
        lcd->setAndPrint("Current status: ", 0, 0);
        lcd->setAndPrint(BARCHAR, bar, 1);
        lcd->setAndPrint(BARCHAR, bar, 2);
        lcd->setAndPrint(BARCHAR, bar, 3);
        counter += myPeriod;
        if(counter % 400 == 0) {
            bar++;
        }
    }
    if (counter >= N3)
    {
        washing = false;
        leaving = true;
        counter = 0;
        bar = 0;
        lcd->clean();
    }
}
#include "LoadBarTask.h"
#define BARCHAR "#"
LoadBarTask ::LoadBarTask(int rows, int column)
{
    this->rows = rows;
    this->column = column;
    counter = 0;
    bar = 1;
}

void LoadBarTask ::init(int period)
{
    lcd = new LcdMonitor(this->rows, this->column);
    Task::init(period);
}

void LoadBarTask ::tick()
{
    if (washing)
    {
        //Serial.println("Loading bar");
        lcd->setAndPrint("Current status: ", 0, 0);
        lcd->setAndPrint(BARCHAR, bar, 1);
        counter += myPeriod;
        if(counter % 1000 == 0) {
            bar++;
        }
    }
    if (counter >= 10000)
    {
        washing = false;
        leaving = true;
        counter = 0;
        lcd->clean();
    }
}
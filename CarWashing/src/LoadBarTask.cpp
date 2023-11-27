#include "LoadBarTask.h"
#define PERIOD 60

LoadBarTask ::LoadBarTask(int rows, int column)
{
    this->rows = rows;
    this->column = column;
    counter = 0;
    bar[0] = ' ';
}

void LoadBarTask ::init(int period)
{
    lcd = new LcdMonitor(this->rows, this->column);
    Task::init(period);
}

void LoadBarTask ::tick()
{
    if (washing && counter < PERIOD)
    {
        Serial.println("Loading bar");
        lcd->setAndPrint(bar, 0, 1);
        strcat(bar, "*");
    }
    else
    {
        washing = false;
        leaving = true;
        counter = 0;
        strcpy(bar, "");
    }
}
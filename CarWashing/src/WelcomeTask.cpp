#include "WelcomeTask.h"

WelcomeTask ::WelcomeTask(int pin, int rows, int columns)
{
    this->pin = pin;
    this->rows = rows;
    this->columns = columns;
    this->counter = 0;
}

void WelcomeTask ::init(int period)
{
    this->period = period;
    led = new Led(pin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void WelcomeTask ::tick()
{
    if (welcome && counter < N1)
    {
        led->switchOn();
        lcd->setAndPrint("Welcome", 1, 0);
        counter += period;
    }
    else
    {
        counter = 0;
        moving = true;
        welcome = false;
    }
}
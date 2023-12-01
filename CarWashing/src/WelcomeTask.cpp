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
    led = new Led(pin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void WelcomeTask ::tick()
{
    if (welcome)
    {
        led->switchOn();
        lcd->clean();
        lcd->setAndPrint("Welcome", 0, 0);
        counter += myPeriod;
    }
    if(counter >= N1)
    {
        counter = 0;
        moving = true;
        welcome = false;
    }
}
#include "LeavingTask.h"
#define DISTANCE 60
#define MAXDISTANCE 1000

LeavingTask ::LeavingTask(int ledPin1, int ledPin2, int rows, int column, int gatePin, int echoPinIn, int trigPinOut, double maxDist)
{
    this->ledPin1 = ledPin1;
    this->ledPin2 = ledPin2;
    this->rows = rows;
    this->column = column;
    this->gatePin = gatePin;
    this->echoPinIn = echoPinIn;
    this->trigPinOut = trigPinOut;
    this->maxDist = maxDist;
    this->counter = 0;
}

void LeavingTask ::init(int period)
{
    led1 = new Led(ledPin1);
    led2 = new Led(ledPin2);
    lcd = new LcdMonitor(rows, column);
    gate = new Gate(gatePin, 90, 0);
    distanceSensor = new Sonar(echoPinIn, trigPinOut);
    Task::init(period);
}

void LeavingTask ::tick()
{
    if (leaving)
    {
        led1->switchOff();
        led2->switchOn();
        lcd->clean();
        lcd->setAndPrint("Washing complete", 0, 0);
        lcd->setAndPrint("You can leave", 0, 1);
        lcd->setAndPrint("The area", 0, 2);
        gate->setOpen();
        if (distanceSensor->getDistance() > this->maxDist)
        {
            counter += myPeriod;
        }
        else
        {
            counter = 0;
        }
    }
    if (counter > N4)
    {
        lcd->clean();
        leaving = false;
        closing = true;
        counter = 0;
    }
}
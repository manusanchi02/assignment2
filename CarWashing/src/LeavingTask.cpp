#include "LeavingTask.h"
#define DISTANCE 60
#define MAXDISTANCE 1000

int distance;

LeavingTask ::LeavingTask(int ledPin1, int ledPin2, int rows, int column, int gatePin, int echoPinIn, int trigPinOut)
{
    this->ledPin1 = ledPin1;
    this->ledPin2 = ledPin2;
    this->rows = rows;
    this->column = column;
    this->gatePin = gatePin;
    this->echoPinIn = echoPinIn;
    this->trigPinOut = trigPinOut;
    distance = 0;
}

void LeavingTask ::init(int period)
{
    led1 = new Led(ledPin1);
    led2 = new Led(ledPin2);
    lcd = new LcdMonitor(rows, column);
    gate = new Gate(gatePin, 0, 90);
    distanceSensor = new Sonar(echoPinIn, trigPinOut);
    Task::init(period);
}

void LeavingTask ::tick()
{
    if (leaving)
    {
        Serial.print("Leaving ");
        led1->switchOff();
        led2->switchOn();
        lcd->clean();
        lcd->setAndPrint("Washing complete, you can leave the area", 1, 0);
        gate->setOpen();
        distance = distanceSensor->getDistance();
        if (distance < minDist)
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
        distance = MAXDISTANCE;
        leaving = false;
        closing = true;
    }
}
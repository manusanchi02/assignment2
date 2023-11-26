#include "ReadyTask.h"
#define PERIOD 60

ReadyTask ::ReadyTask(int ledPin, int gatePin, int echoPin, int trigPin, float minDistance, int rows, int columns)
{
    this->ledPin = ledPin;
    this->gatePin = gatePin;
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->minDistance = minDistance;
    this->rows = rows;
    this->columns = columns;
    counter = 0;
}

void ReadyTask ::init(int period)
{
    led = new Led(ledPin);
    gate = new Gate(this->gatePin, 0, 90);
    sonar = new Sonar(echoPin, trigPin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void ReadyTask ::tick()
{
    if (ready && counter < PERIOD && sonar->getDistance() < minDistance)
    {
        led->switchOn();
        lcd->setAndPrint("Ready to wash", 1, 0);
        gate->setClose();
        counter++;
    }
    else
    {
        washing = true;
        ready = false;
    }
}
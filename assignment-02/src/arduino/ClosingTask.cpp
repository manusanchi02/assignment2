#include "ClosingTask.h"
int counter;

ClosingTask ::ClosingTask(int gatePin, int gateOpen, int gateClose,  int ledPin)
{
    this->gatePin = gatePin;
    this->gateOpen = gateOpen;
    this->gateClose = gateClose;
    this->ledPin = ledPin;
    counter = 0; // counter for the time spent in this state
}

void ClosingTask ::init(int period)
{
    gate = new Gate(gatePin, gateOpen, gateClose);
    led = new Led(ledPin);
    Task::init(period);
}

void ClosingTask ::tick()
{
    if (closing && !error)
    {
        gate->setClose();
        led->switchOff();
        counter += myPeriod;
    }
    if (counter > N2) {
        sleeping = true;
        closing = false;
        counter = 0;
    }
}
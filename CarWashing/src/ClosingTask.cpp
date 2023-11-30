#include "ClosingTask.h"
int counter;

ClosingTask ::ClosingTask(int gatePin, int gateOpen, int gateClose,  int ledPin)
{
    this->gatePin = gatePin;
    this->gateOpen = gateOpen;
    this->gateClose = gateClose;
    this->ledPin = ledPin;
    counter = 0;
}

void ClosingTask ::init(int period)
{
    gate = new Gate(gatePin, gateOpen, gateClose);
    led = new Led(ledPin);
    Task::init(period);
}

void ClosingTask ::tick()
{
    if (closing)
    {
        //Serial.println("Closing");
        gate->setClose();
        led->switchOff();
        counter += myPeriod;
        Serial.println(counter);
    }
    if (counter > N2) {
        Serial.println("fine closing");
        sleeping = true;
        closing = false;
        counter = 0;
    }
}
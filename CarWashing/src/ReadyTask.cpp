#include "ReadyTask.h"
#define PERIOD 60
volatile bool buttonPressed = false;

void buttonHandler()
{
    buttonPressed = true;
    Serial.println("Button pressed");
}

ReadyTask ::ReadyTask(int ledPin, int gatePin, int rows, int columns, int buttonPin)
{
    this->ledPin = ledPin;
    this->gatePin = gatePin;
    this->rows = rows;
    this->columns = columns;
    this->buttonPin = buttonPin;
}

void ReadyTask ::init(int period)
{
    led = new Led(ledPin);
    gate = new Gate(this->gatePin, 90, 0);
    lcd = new LcdMonitor(rows, columns);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonHandler, CHANGE);
    Task::init(period);
}

void ReadyTask ::tick()
{
    if (ready)
    {
        Serial.println("Ready");
        led->switchOn();
        lcd->clean();
        lcd->setAndPrint("Ready to wash", 1, 0);
        gate->setClose();
    }
    if (ready && buttonPressed)
    {
        buttonPressed = false;
        washing = true;
        ready = false;
    }
}
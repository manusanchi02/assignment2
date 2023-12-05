#include "ReadyTask.h"

// Variable to check if the button has been pressed.
volatile bool buttonPressed = false;

/**
 * Function to handle the button interrupt.
 */
void buttonHandler()
{
    buttonPressed = true;
}

ReadyTask ::ReadyTask(int ledPin, int gatePin, int gateOpen, int gateClose, int rows, int columns, int buttonPin)
{
    this->ledPin = ledPin;
    this->gatePin = gatePin;
    this->rows = rows;
    this->columns = columns;
    this->buttonPin = buttonPin;
    this->gateOpen = gateOpen;
    this->gateClose = gateClose;
}

void ReadyTask ::init(int period)
{
    led = new Led(ledPin);
    gate = new Gate(this->gatePin, gateOpen, gateClose);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonHandler, CHANGE);
}

void ReadyTask ::tick()
{
    if (ready && !error)
    {
        led->switchOn();
        lcd->clean();
        lcd->setAndPrint("Ready to wash", 0, 0);
        gate->setClose();
        if (buttonPressed)
        {
            washing = true;
            ready = false;
            lcd->clean();
        }
    }
    buttonPressed = false;
}
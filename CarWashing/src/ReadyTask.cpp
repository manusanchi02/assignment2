#include "ReadyTask.h"
//#include <EnableInterrupt.h>

volatile bool buttonPressed = false;
volatile bool interruptEnabled = false;

void buttonHandler()
{
    buttonPressed = true;
    Serial.println("Button pressed sopra");
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
    //enableInterrupt(buttonPin, buttonHandler, CHANGE);
    Task::init(period);
}

void ReadyTask ::tick()
{
    if (ready)
    {
        if(!interruptEnabled) {
            attachInterrupt(digitalPinToInterrupt(buttonPin), buttonHandler, CHANGE);
        }
        Serial.println("Ready");
        led->switchOn();
        lcd->clean();
        lcd->setAndPrint("Ready to wash", 1, 0);
        gate->setClose();
        if(buttonPressed) {
            //Serial.println("Button pressed sotto");
            buttonPressed = false;
            washing = true;
            ready = false;
            lcd->clean();
            //disableInterrupt(buttonPin);
            detachInterrupt(digitalPinToInterrupt(buttonPin));
        }
    }
}
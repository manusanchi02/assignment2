#include "WelcomeTask.h"

int counter;

WelcomeTask :: WelcomeTask(int pin, int rows, int columns) {
    this->pin = pin;
    this->rows = rows;
    this->columns = columns;
}

void WelcomeTask :: init(int period) {
    led = new Led(pin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void WelcomeTask :: tick() {
    led->switchOn();
    lcd->setAndPrint("Welcome", 1, 0);
    
}
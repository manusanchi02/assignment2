#include "WelcomeTask.h"
#define PERIOD 60
int counter;

WelcomeTask :: WelcomeTask(int pin, int rows, int columns) {
    this->pin = pin;
    this->rows = rows;
    this->columns = columns;
    counter = 0;
}

void WelcomeTask :: init(int period) {
    led = new Led(pin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void WelcomeTask :: tick() {
    if(welcome && counter < PERIOD) {
        led->switchOn();
        lcd->setAndPrint("Welcome", 1, 0);
        counter++;
    } else {
        moving = true;
        welcome = false;
    }
}
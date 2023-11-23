#include "ReadyTask.h"
#define PERIOD 60
int counter;

ReadyTask :: ReadyTask(int ledPin, int gatePin, int echoPin, int trigPin, int rows, int columns) {
    this->ledPin = ledPin;
    this->gatePin = gatePin;
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->rows = rows;
    this->columns = columns;
    counter = 0;
}

void ReadyTask :: init(int period) {
    led = new Led(ledPin);
    gate = new Gate(gatePin);
    sonar = new Sonar(echoPin, trigPin);
    lcd = new LcdMonitor(rows, columns);
    Task::init(period);
}

void ReadyTask :: tick() {
    if(ready && counter < PERIOD && sonar->getDistance() > 10) {
        led->switchOn();
        lcd->setAndPrint("Ready to wash", 1, 0);
        gate->close();
        counter++;
    } else {
        washing = true;
        ready = false;
        moving = false;
        welcome = false;
    }
}
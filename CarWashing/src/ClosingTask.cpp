#include "ClosingTask.h"
#define PERIOD 60
int counter;

ClosingTask :: ClosingTask(int gatePin,int gateOpen,int gateClose, int echoPin, int trigPin, float maxDistance) {
    this->gatePin = gatePin;
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->maxDistance = maxDistance;
    counter = 0;
}

void ClosingTask :: init(int period) {
    gate = new Gate(gatePin, gateOpen, gateClose);
    sonar = new Sonar(echoPin, trigPin, 0.034);
    Task::init(period);
}

void ClosingTask :: tick() {
    if(closing && counter < PERIOD && sonar->getDistance() > maxDistance) {
        gate->close();
        counter++;
    } else {
        sleeping = true;
        closing = false;
    }
}
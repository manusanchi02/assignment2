#ifndef __WELCOMETASK__
#define __WELCOMETASK__
#include "Task.h"
#include "Led.h"
#include "Gate.h"
#include "Sonar.h"
#include "LcdMonitor.h"

class ReadyTask : public Task {
    public:
        /**
         * Class constructor:
         * @param pin number of the led pin
        */
        ReadyTask(int ledPin, int gatePin, int echoPin, int trigPin, int int rows, int columns);
        /**
         * Init method.
         * @param period task period
         * @param rows number of lcd rows
         * @param columns number of lcd columns
        */
        void init(int period);
        /**
         * Tick method.
        */
        void tick();
    protected:
        int ledPin;
        int gatePin;
        int echoPin;
        int trigPin;
        int rows;
        int columns;
        Led* led;
        Gate* gate;
        Sonar* sonar;
        LcdMonitor* lcd;
};

#endif
#ifndef __COMUNICATIONTASK_H__
#define __COMUNICATIONTASK_H__
#include "Task.h"
#include <Arduino.h>
#include "TemperatureSensor.h"

class CommunicationTask : public Task
{
    public:
    /**
     * Constructor for the ComunicationTask class.
     * @param pin the pin of temperature sensor.
    */
        CommunicationTask(int pin);
        /**
         * Initializes the ComunicationTask.
        */
        void init(int period);
        /**
         * Executes the ComunicationTask.
        */
        void tick();
    protected:
        int pin;
        TemperatureSensor *ts;
};
#endif
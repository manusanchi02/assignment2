#ifndef __COMUNICATIONTASK_H__
#define __COMUNICATIONTASK_H__
#include "Task.h"
#include <Arduino.h>
#include "TemperatureSensor.h"
#include "LcdMonitor.h"

class CommunicationTask : public Task
{
    public:
    /**
     * Constructor for the ComunicationTask class.
     * @param pin the pin of temperature sensor.
     * @param rows the number of rows of the LCD.
     * @param cols the number of columns of the LCD.
    */
        CommunicationTask(int pin, int rows, int cols);
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
        int rows;
        int cols;
        int counter;
        LcdMonitor *lcd;
        TemperatureSensor *ts;
};
#endif
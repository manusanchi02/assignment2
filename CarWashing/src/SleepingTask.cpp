#include "SleepingTask.h"

void wakeUp()
{
    sleeping = false;
}

SleepingTask::SleepingTask(int pirPin, int ledpin)
{
    this->pirPin = pirPin;
    this->ledpin = ledpin;
}

void SleepingTask::init(int period)
{
    pinMode(ledpin, OUTPUT);
    Task::init(period);
}

void SleepingTask::tick()
{
    if (sleeping)
    {
        attachInterrupt(digitalPinToInterrupt(pirPin), wakeUp, RISING);
        digitalWrite(ledpin, LOW);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        power_adc_disable();
        power_spi_disable();
        power_twi_disable();
        sleep_mode();
        // in this point arduino wake up
        sleep_disable();
        power_all_enable();
        welcome = true;
        sleeping = false;
        carCounter++;
        detachInterrupt(digitalPinToInterrupt(pirPin));
    }
}
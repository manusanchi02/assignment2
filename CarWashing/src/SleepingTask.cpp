#include "SleepingTask.h"

void wakeUp()
{
    sleeping = false;
}

SleepingTask::SleepingTask(int pirPin)
{
    this->pirPin = pirPin;
}

void SleepingTask::init()
{
    attachInterrupt(digitalPinToInterrupt(pirPin), wakeUp, CHANGE);
}

void SleepingTask::tick()
{
    if (sleeping)
    {
        //Serial.println("Sleeping");
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        power_adc_disable();
        power_spi_disable();
        power_twi_disable();
        sleep_mode();
        // in this point arduino wake up
        //Serial.println("Waking up");
        sleep_disable();
        power_all_enable();
        welcome = true;
    }
}
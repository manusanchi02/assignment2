#include "SleepingTask.h"
#include <avr/sleep.h>
#include <avr/power.h>

SleepingTask::SleepingTask()
{
    counter = 0;
}

void SleepingTask::init()
{
}

void SleepingTask::tick()
{

    if (sleeping && counter < 1)
    {
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        power_adc_disable();
        power_spi_disable();
        power_twi_disable();
        sleep_mode();
        // in this point arduino wake up
        sleep_disable();
        power_all_enable();
        counter++;
    }
    else
    {
        sleeping = false;
        welcome = true;
    }
}
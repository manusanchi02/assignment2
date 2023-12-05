#ifndef __TASK__
#define __TASK__
#include <Arduino.h>
#include "GlobalVariables.h"

class Task
{
	int timeElapsed;

public:
	/**
	 * Init method called once at the beginning of the task
	 * to initialize its variables.
	 * @param period task period
	 */
	virtual void init(int period)
	{
		myPeriod = period;
		timeElapsed = 0;
	}

	/**
	 * Tick method.
	 */
	virtual void tick() = 0;

	/**
	 * Method to update the time elapsed and check if the task is ready to run.
	 */
	bool updateAndCheckTime(int basePeriod)
	{
		timeElapsed += basePeriod;
		if (timeElapsed >= myPeriod)
		{
			timeElapsed = 0;
			return true;
		}
		else
		{
			return false;
		}
	}

protected:
	int myPeriod;
};

#endif

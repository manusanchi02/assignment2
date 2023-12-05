#ifndef __TASK__
#define __TASK__
#include <Arduino.h>
#include "GlobalVariables.h"

#define N1 5000
#define N2 2000
#define N3 8000
#define N4 3000
#define N5 4000
#define MAXDIST 0.30
#define MINDIST 0.10
#define ERROR_TEMPERATURE 50

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

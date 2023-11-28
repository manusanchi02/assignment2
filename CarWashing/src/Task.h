#ifndef __TASK__
#define __TASK__
#include <Arduino.h>
#define N1 5000
#define N2 2000

class Task
{
	int myPeriod;
	int timeElapsed;

public:
	virtual void init(int period)
	{
		myPeriod = period;
		timeElapsed = 0;
	}

	virtual void tick() = 0;

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
	float minDist;
	bool isNear = false;
	bool washing = false;
	bool moving = false;
	bool welcome = true;
	bool ready = false;
	bool closing = false;
	bool sleeping = false;
	bool leaving = false;
};

#endif

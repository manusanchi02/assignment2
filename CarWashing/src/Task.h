#ifndef __TASK__
#define __TASK__

class Task {
	int myPeriod;
	int timeElapsed;

public:
	virtual void init(int period) {
		myPeriod = period;
		timeElapsed = 0;
	}

	virtual void tick() = 0;

	bool updateAndCheckTime(int basePeriod) {
		timeElapsed += basePeriod;
		if (timeElapsed >= myPeriod) {
			timeElapsed = 0;
			return true;
		}
		else {
			return false;
		}
	}

	protected: 
		bool washing = false;
		bool moving = false;
		bool welcome = true;
		bool leaving = true;
};

#endif

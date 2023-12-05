#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 50

class Scheduler
{

  int basePeriod;
  int nTasks;
  Task *taskList[MAX_TASKS];

public:
  /**
   * Init method.
   * @param basePeriod base period of the scheduler
   */
  void init(int basePeriod);
  /**
   * Method to add a task to the scheduler.
   */
  virtual bool addTask(Task *task);
  /**
   * Method to call all the tasks thick method.
   */
  virtual void schedule();
};

#endif

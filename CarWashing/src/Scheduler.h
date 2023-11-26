#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

using namespace std;

#define MAX_TASKS 50

class Scheduler
{

  int basePeriod;
  int nTasks;
  Task *taskList[MAX_TASKS];

public:
  void init(int basePeriod);
  virtual bool addTask(Task *task);
  virtual bool removeTask(Task *task);
  virtual void schedule();
};

#endif

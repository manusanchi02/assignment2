#include "Scheduler.h"
#include "GlobalVariables.h"

// Variable used to check the scheduler basePeriod.
volatile long currentMillis = 0;
// Variable used to check if the scheduler has to schedule.
volatile long timerFlag = false;

void Scheduler::init(int basePeriod)
{
  this->basePeriod = basePeriod;
  timerFlag = false;
  nTasks = 0;
}

bool Scheduler::addTask(Task *task)
{
  if (nTasks < MAX_TASKS - 1)
  {
    taskList[nTasks] = task;
    nTasks++;
    return true;
  }
  else
  {
    return false;
  }
}

void Scheduler::schedule()
{
  while (!timerFlag)
  {
    if ((long)millis() - currentMillis > basePeriod)
    {
      currentMillis = millis();
      timerFlag = true;
    }
  }

  timerFlag = false;

  for (int i = 0; i < nTasks; i++)
  {
    if (taskList[i]->updateAndCheckTime(basePeriod))
    {
      taskList[i]->tick();
    }
  }
}

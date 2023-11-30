#include "Scheduler.h"
#include <TimerOne.h>
#include "GlobalVariables.h"

volatile bool timerFlag;

void timerHandler(void){
  //Serial.println("timerScattato");
  timerFlag = true;
}

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}

void Scheduler::schedule(){   
  while (!timerFlag){/*long counter = TCNT1;
  Serial.println(counter);*/
  /*if(!timerFlag)
  timerFlag = true;*//*
  if(washing)
  Serial.println("washing");
  if(moving)
  Serial.println("moving");
  if(welcome)
  Serial.println("welcome");
  if(ready)
  Serial.println("ready");
  if(closing)
  Serial.println("closing");
  if(sleeping)
  Serial.println("sleeping");
  if(leaving)
  Serial.println("leaving");
  ;
  if(!welcome && !moving && !washing && !ready && !closing && !sleeping && !leaving)
  Serial.println("idle");
  if(closing)
  taskList[3]->tick();*/
  }

  timerFlag = false;
  Timer1.attachInterrupt(timerHandler, 1000l*basePeriod);
  /*long counter = TCNT1;
  Serial.println(counter);*/


  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->updateAndCheckTime(basePeriod)){
      taskList[i]->tick();
    }
  }
}




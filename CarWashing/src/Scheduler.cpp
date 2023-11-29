#include "Scheduler.h"
#include <TimerOne.h>

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

void Timer1Initialize() {
    noInterrupts();
    Timer1.initialize();
    Timer1.stop();
    interrupts();
}

void Timer1setPeriod(void (*isr)(), unsigned long microseconds) {
    noInterrupts();
    Timer1.attachInterrupt(isr, microseconds);
    interrupts();
}

void Scheduler::schedule(){   
  while (!timerFlag){}
  //Timer1Initialize();
  //Timer1setPeriod(timerHandler, 1000l*basePeriod);
  Timer1.attachInterrupt(timerHandler, 1000l*basePeriod);
  /*long counter = TCNT1;
  Serial.println(counter);*/
  timerFlag = false;

  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->updateAndCheckTime(basePeriod)){
      taskList[i]->tick();
    }
  }
}




#include "ApproachTask.h"
#include "MovingTask.h"
#include "LeavingTask.h"
#include "BlinkTask.h"
#include "ClosingTask.h"
#include "LoadBarTask.h"
#include "ReadyTask.h"
#include "SleepingTask.h"
#include "WashBlinkTask.h"
#include "Scheduler.h"
#include "WelcomeTask.h"
#define MAXDIST 20
#define MIDISTANCE 5

Scheduler sched;

void setup()
{
	Serial.begin(9600);
	sched.init(50);
/*
	Task *t0 = new SleepingTask();
	t0->init(100);
	sched.addTask(t0);
	Task *t1 = new MovingTask(0, 3, 16, 9, 90, 0);
	t1->init(100);
	sched.addTask(t1);
	Task *t2 = new ApproachTask(7, 6);
	t2->init(100);
	sched.addTask(t2);
	Task *t3 = new LeavingTask(12, 11, 3, 16, 9, 7, 6);
	t3->init(100);
	sched.addTask(t3);
	Task *t4 = new BlinkTask(12);
	t4->init(100);
	sched.addTask(t4);
	Task *t5 = new ClosingTask(9, 90, 0, 6, 7, MAXDIST);
	t5->init(100);
	sched.addTask(t5);
	Task *t6 = new LoadBarTask(3, 16);
	t6->init(100);
	sched.addTask(t6);
	Task *t7 = new ReadyTask(12, 9, 6, 7, MIDISTANCE, 3, 16);
	t7->init(100);
	sched.addTask(t7);
	Task *t8 = new WashBlinkTask(11);
	t8->init(100);
	sched.addTask(t8);*/
	Task *t9 = new WelcomeTask(13, 3, 16);
	t9->init(100);
	sched.addTask(t9);

}
void loop()
{
	sched.schedule();
	Serial.print("c");
}
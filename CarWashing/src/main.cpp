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

Scheduler sched;

void setup() {
	sched.init(50);

	Task* t0 = new SleepingTask();
	t0->init(500);
	sched.addTask(t0);
	Task* t1 = new MovingTask(12, 2, 16, 8, 9, 10);
	t1->init(150);
	sched.addTask(t1); 
	Task* t2 = new ApproachTask(11, 13, 7);
	t2->init(100);
	sched.addTask(t2);
	Task* t3 = new LeavingTask(13, 12, 16, 8, 9, 10, 11, 7);
	t3->init(100);
	sched.addTask(t3);
	Task* t4 = new BlinkTask(3);
	t4->init(100);
	sched.addTask(t4);
	// insert all tasks
	Task* t5 = new ClosingTask(8, 1, 0, 13, 12, 52);
	t5->init(100);
	sched.addTask(t5);
	Task* t6 = new LoadBarTask(16, 8);
	t6->init(100);
	sched.addTask(t6);
	Task* t7 = new ReadyTask(12, 16, 8, 9, 10, 11, 7);
	t7->init(100);
	sched.addTask(t7);
	Task* t8 = new WashBlinkTask(3);
	t8->init(100);
	sched.addTask(t8);
	Task* t9 = new WashBlinkTask(3);
	t9->init(100);
	sched.addTask(t9);
	Task* t10 = new WashBlinkTask(3);
	t10->init(100);
	sched.addTask(t10);
	Task* t11 = new WashBlinkTask(3);
	t11->init(100);
	sched.addTask(t11);

}
void loop() {
	sched.schedule();
}
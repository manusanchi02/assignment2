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
#define MAXDIST 0.40
#define MIDISTANCE 0.10
#define LEDPIN1 13
#define LEDPIN2 12
#define LEDPIN3 11
#define LCDROWS 3
#define LCDCOLS 16
#define GATEPIN 9
#define GATEOPEN 90
#define GATECLOSE 0
#define TRIGPIN 7
#define ECHOPIN 6


Scheduler sched;

void setup()
{
	Serial.begin(9600);
	sched.init(50);

	Task *t0 = new WelcomeTask(LEDPIN1, LCDROWS, LCDCOLS);
	t0->init(100);
	sched.addTask(t0);
	Task *t1 = new MovingTask(LCDROWS, LCDCOLS, GATEPIN, GATEOPEN, GATECLOSE);
	t1->init(100);
	sched.addTask(t1);
	Task *t2 = new BlinkTask(LEDPIN2);
	t2->init(100);
	sched.addTask(t2);
	Task *t3 = new ApproachTask(TRIGPIN, ECHOPIN);
	t3->init(100);
	sched.addTask(t3);
	Task *t4 = new ReadyTask(LEDPIN2, GATEPIN, ECHOPIN, TRIGPIN, MIDISTANCE, LCDROWS, LCDCOLS);
	t4->init(100);
	sched.addTask(t4);
	Task *t5 = new WashBlinkTask(LEDPIN3);
	t5->init(100);
	sched.addTask(t5);
	Task *t6 = new LoadBarTask(LCDROWS, LCDCOLS);
	t6->init(100);
	sched.addTask(t6);
	Task *t7 = new LeavingTask(LEDPIN2, LEDPIN3, LCDROWS, LCDCOLS, GATEPIN, ECHOPIN, TRIGPIN);
	t7->init(100);
	sched.addTask(t7);
	Task *t8 = new ClosingTask(GATEPIN, GATEOPEN, GATECLOSE, ECHOPIN, TRIGPIN, MAXDIST);
	t8->init(100);
	sched.addTask(t8);
	Task *t9 = new SleepingTask();
	t9->init(100);
	sched.addTask(t9);

}
void loop()
{
	sched.schedule();
	Serial.print("c");
}
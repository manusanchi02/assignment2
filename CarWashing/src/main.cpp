/**
 * @author lorenzo.annibalini@studio.unibo.it
 * @author lorenzo.bacchini4@studio.unibo.it
 * @author emanuele.sanchi@studio.unibo.it
 */
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
#include "CommunicationTask.h"
#include "Gate.h"
#include "TemperatureSensor.h"
#include "GlobalVariables.h"
#include "LcdMonitor.h"

#define LEDPIN1 13
#define LEDPIN2 12
#define LEDPIN3 11
#define LCDROWS 4
#define LCDCOLS 20
#define GATEPIN 9
#define GATEOPEN 90
#define GATECLOSE 0
#define TRIGPIN 7
#define ECHOPIN 8
#define BUTTONPIN 2
#define PIRPIN 3
#define TEMPERATUREPIN A0


Scheduler sched;
LcdMonitor *lcd;

void setup()
{
	lcd = new LcdMonitor(LCDROWS, LCDCOLS);
	// calibrate sensors
	lcd->setAndPrint("Calibrating sensors", 0, 0);
	//delay(10000);

	Serial.begin(9600);
	sched.init(100);

	Task *t0 = new WelcomeTask(LEDPIN1, LCDROWS, LCDCOLS);
	t0->init(200);
	sched.addTask(t0);
	Task *t1 = new MovingTask(LCDROWS, LCDCOLS, GATEPIN, GATEOPEN, GATECLOSE);
	t1->init(400);
	sched.addTask(t1);
	Task *t2 = new BlinkTask(LEDPIN2);
	t2->init(100);
	sched.addTask(t2);
	Task *t3 = new ApproachTask(TRIGPIN, ECHOPIN);
	t3->init(200);
	sched.addTask(t3);
	Task *t4 = new ReadyTask(LEDPIN2, GATEPIN, GATEOPEN, GATECLOSE, LCDROWS, LCDCOLS, BUTTONPIN);
	t4->init(200);
	sched.addTask(t4);
	Task *t5 = new WashBlinkTask(LEDPIN2);
	t5->init(500);
	sched.addTask(t5);
	Task *t6 = new LoadBarTask(LCDROWS, LCDCOLS);
	t6->init(100);
	sched.addTask(t6);
	Task *t7 = new LeavingTask(LEDPIN2, LEDPIN3, LCDROWS, LCDCOLS, GATEPIN, GATECLOSE, GATEOPEN, ECHOPIN, TRIGPIN);
	t7->init(300);
	sched.addTask(t7);
	Task *t8 = new ClosingTask(GATEPIN, GATEOPEN, GATECLOSE, LEDPIN3);
	t8->init(400);
	sched.addTask(t8);
	Task *t9 = new SleepingTask(PIRPIN, LEDPIN1);
	t9->init(50);
	sched.addTask(t9);
	Task *t10 = new CommunicationTask(TEMPERATUREPIN, LCDROWS, LCDCOLS);
	t10->init(500);
	sched.addTask(t10);
}
void loop()
{
	sched.schedule();
}
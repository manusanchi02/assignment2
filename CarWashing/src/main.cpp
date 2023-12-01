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
#include "Gate.h"
#include "TemperatureSensor.h"
#include "GlobalVariables.h"
#define MAXDIST 0.80
#define MINDIST 0.30
#define LEDPIN1 13
#define LEDPIN2 12
#define LEDPIN3 11
#define LCDROWS 3
#define LCDCOLS 16
#define GATEPIN 9
#define GATEOPEN 90
#define GATECLOSE 0
#define TRIGPIN 7
#define ECHOPIN 8
#define BUTTONPIN 3
#define PIRPIN 2
#define TEMPERATUREPIN A0


Scheduler sched;
TemperatureSensor *ts;

String serialCommunication() {
	String message = "";
	String state = "State: ";
	if(welcome)
		state = "Welcome";
	else if(moving)
		state = "Moving";
	else if(ready)
		state = "Ready";
	else if(leaving)
		state = "Leaving";
	else if(closing)
		state = "Closing";
	else if(sleeping)
		state = "Sleeping";
	String temperature = "Temperature: " + String(ts->getTemperature());
	String cars = "Car Counter: " + String(carCounter);
	message = state + " " + temperature + " " + cars;
	return message;
}

void setup()
{
	Serial.begin(9600);
	sched.init(100);
	ts = new TemperatureSensor(TEMPERATUREPIN);

	Task *t0 = new WelcomeTask(LEDPIN1, LCDROWS, LCDCOLS);
	t0->init(200);
	sched.addTask(t0);
	Task *t1 = new MovingTask(LCDROWS, LCDCOLS, GATEPIN, GATEOPEN, GATECLOSE);
	t1->init(400);
	sched.addTask(t1);
	Task *t2 = new BlinkTask(LEDPIN2);
	t2->init(250);
	sched.addTask(t2);
	Task *t3 = new ApproachTask(TRIGPIN, ECHOPIN, MINDIST);
	t3->init(200);
	sched.addTask(t3);
	Task *t4 = new ReadyTask(LEDPIN2, GATEPIN, GATEOPEN, GATECLOSE, LCDROWS, LCDCOLS, BUTTONPIN);
	t4->init(200);
	sched.addTask(t4);
	Task *t5 = new WashBlinkTask(LEDPIN3);
	t5->init(250);
	sched.addTask(t5);
	Task *t6 = new LoadBarTask(LCDROWS, LCDCOLS);
	t6->init(100);
	sched.addTask(t6);
	Task *t7 = new LeavingTask(LEDPIN2, LEDPIN3, LCDROWS, LCDCOLS, GATEPIN, GATEOPEN, GATECLOSE, ECHOPIN, TRIGPIN, MAXDIST);
	t7->init(300);
	sched.addTask(t7);
	Task *t8 = new ClosingTask(GATEPIN, GATEOPEN, GATECLOSE, LEDPIN3);
	t8->init(400);
	sched.addTask(t8);
	Task *t9 = new SleepingTask(PIRPIN, LEDPIN1);
	t9->init(50);
	sched.addTask(t9);
}
void loop()
{
	sched.schedule();
	Serial.print(serialCommunication());
}
#include "CommunicationTask.h"
#include "GlobalVariables.h"

String previousState = "Welcome";
float previousTemp = 0;
int previousCars = 0;

void checkSerial() {
    Serial.read();
    String msg = Serial.read();
    if(msg == "tError") {

    }
}

CommunicationTask::CommunicationTask(int pin)
{
    this->pin = pin;
}

void CommunicationTask::init(int period)
{
    ts = new TemperatureSensor(pin);
    Task::init(period);
}

void CommunicationTask::tick()
{
    String state = "";
	if(welcome)
		state = "Welcome";
	else if(moving)
		state = "Moving";
	else if(ready)
		state = "Ready";
    else if(washing)
        state = "Washing";
    else if(leaving)
		state = "Leaving";
	else if(closing)
		state = "Closing";
	else if(sleeping)
		state = "Sleeping";
    float temp = ts->getTemperature();
	String temperature = "temp:" + String(temp);
    if(previousState != state){
	    Serial.println("state:" + state);
        previousState = state;
    }
    if(previousTemp - temp < -0.5 || previousTemp - temp > 0.5) {
	    Serial.println("temp:" + String(ts->getTemperature()));
        previousTemp = temp;
    }

    if(previousCars != carCounter) {
	    Serial.println("cars:" + String(carCounter));
        previousCars = carCounter;
    }

    //checkSerial();
}
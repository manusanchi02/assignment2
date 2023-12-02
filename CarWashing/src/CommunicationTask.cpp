#include "CommunicationTask.h"
#include "GlobalVariables.h"

String previousState = "Welcome";
float previousTemp = 0;
int previousCars = 0;

void checkSerial() {
    String msg = Serial.readStringUntil('\n');
    if(msg == "tRestart") {
        error = false;
    }
}

CommunicationTask::CommunicationTask(int pin, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->pin = pin;
}

void CommunicationTask::init(int period)
{
    ts = new TemperatureSensor(pin);
    lcd = new LcdMonitor(rows, cols);
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
        if(previousTemp >= errorTemperature){
            Serial.println("error:Temperature Error");
            lcd->clean();
            lcd->setAndPrint("Detected a Problem", 0, 0);
            lcd->setAndPrint("-", 0, 1);
            lcd->setAndPrint("Please Wait", 0, 2);
            error = true;
        }
    }
    if(previousCars != carCounter) {
	    Serial.println("cars:" + String(carCounter));
        previousCars = carCounter;
    }

    checkSerial();
}
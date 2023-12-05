#include "CommunicationTask.h"
#include "GlobalVariables.h"

String previousState = "Welcome";
float previousTemp = 0;
int previousCars = 0;


void checkSerial() {
    int msg = Serial.read();
    if(msg != -1) {
        error = false;
    }
}

CommunicationTask::CommunicationTask(int pin, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->pin = pin;
    this->counter = 0;
}

void CommunicationTask::init(int period)
{
    ts = new TemperatureSensor(pin);
    lcd = new LcdMonitor(rows, cols);
    Task::init(period);
}

void CommunicationTask::tick()
{
    // to avoid multiple prints of the same message we use a previous state variable 
    // and we check if the state is changed. We also do the same for the temperature
    // and the number of cars
    
    // condition to check what state we are in
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
    // condition to check if the state is changed
    if(previousState != state){
	    Serial.println("state:" + state);
        previousState = state;
    }
    // condition to check if the temperature is changed by more than 0.5
    if(previousTemp - temp < -0.5 || previousTemp - temp > 0.5) {
	    Serial.println("temp:" + String(ts->getTemperature()));
        previousTemp = temp;
        if(previousTemp >= ERROR_TEMPERATURE){
            counter += myPeriod;
        }else{
            counter = 0;
        }
        if(counter >= N5){
            counter = 0;
            Serial.println("error:Maintenance required");
            lcd->clean();
            lcd->setAndPrint("Detected a Problem", 0, 0);
            lcd->setAndPrint("-", 10, 1);
            lcd->setAndPrint("Please Wait", 0, 2);
            error = true;
        }
    }
    // condition to check if the number of cars is changed
    if(previousCars != carCounter) {
	    Serial.println("cars:" + String(carCounter));
        previousCars = carCounter;
    }
    // call the function to check if there is a message from the serial by the Gui
    checkSerial();
}
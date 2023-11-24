#include <Timer.h>
#include "ApproachTask.h"
#include "MovingTask.h"
#include "WashingTask.h"
#include "LeavingTask.h"
#include "BlinkTask.h"
#include "ClosingTask.h"
#include "LoadBarTask.h"
#include "ReadyTask.h"
#include "SleepingTask.h"
#include "WashBlinkTask.h"

Timer timer;
BlinkTask blinkTask(2);
ThreeLedsTask threeLedsTask(3,4,5);
void setup(){
 blinkTask.init();
 threeLedsTask.init();
 timer.setupPeriod(500);
}
void loop(){
 timer.waitForNextTick();
 blinkTask.tick();
 threeLedsTask.tick();
}
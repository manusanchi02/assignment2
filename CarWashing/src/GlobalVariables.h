// Various global variables used in the project for states and other purposes.
#define N1 5000
#define N2 2000
#define N3 8000
#define N4 3000
#define N5 4000
#define MAXDIST 0.30
#define MINDIST 0.10
#define ERROR_TEMPERATURE 50

extern volatile bool isNear;
extern volatile bool error;
extern volatile bool washing;
extern volatile bool moving;
extern volatile bool welcome;
extern volatile bool ready;
extern volatile bool closing;
extern volatile bool sleeping;
extern volatile bool leaving;
extern volatile bool gateState;
extern volatile int carCounter;
extern volatile float errorTemperature;
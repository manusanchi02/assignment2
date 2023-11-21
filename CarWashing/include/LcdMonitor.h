#ifndef __MONITOR__
#define __MONITOR__
#include <LiquidCrystal_I2C.h> 
class LcdMonitor {
    public:
        LcdMonitor(int rows, int columns);
        void setAndPrint(char* string, int xposition, int yposition);
};
#endif
#ifndef __GATE__
#define __GATE__

#include <Servo.h>

class Gate
{
public:
    Gate(int pin, int open, int close);
    void setOpen();
    void setClose();
    bool isOpen();

protected:
    int pin;
    int open;
    int close;
    bool state;
    Servo servo;
};
#endif
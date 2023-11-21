#ifndef __LED__
#define __LED__
class Led {
    public:
        Led(int pin);
        void switchOn();
        void switchOff();
        bool isOn();
    protected:
        int pin;
        bool state;
};
#endif
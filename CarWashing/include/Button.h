#ifndef __BUTTON__
#define __BUTTON__
class Button {
    public:
        Button(int pin);
        bool isPressed();
    protected:
        int pin; 
};
#endif
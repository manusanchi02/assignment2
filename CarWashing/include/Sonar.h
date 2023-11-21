#ifndef __SONAR__
#define __SONAR__
class Sonar {
    public:
        Sonar(int echoPinIn, int trigPinOut, float velocitaSuono);
        float getDistance();
    protected:
        int echoPinIn;
        int trigPinOut;
        float velocitaSuono; 
};
#endif
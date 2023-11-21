#ifndef __TEMPERATURESENSOR__
#define __TEMPERATURESENSOR__
class TemperatureSensor {
    public:
        TemperatureSensor(int pin);
        float getTemperature();
    protected:
        int pin; 
};
#endif
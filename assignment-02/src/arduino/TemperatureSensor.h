#ifndef __TEMPERATURESENSOR__
#define __TEMPERATURESENSOR__
class TemperatureSensor
{
public:
    /**
     * Class constructor.
     * @param pin number of the pin where the temperature sensor is connect.
     */
    TemperatureSensor(int pin);
    /**
     * Method to get the temperature.
     */
    float getTemperature();

protected:
    int pin;
};
#endif
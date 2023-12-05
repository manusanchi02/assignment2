#ifndef __PIR__
#define __PIR__
class Pir
{
public:
    /**
     * Class constructor.
     * @param pin number of the pin where the pir is connect.
     */
    Pir(int pin);
    /**
     * Method to check if the pir detected something.
     */
    bool isDetected();

protected:
    int pin;
};
#endif
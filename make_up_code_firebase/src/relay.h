#include <Arduino.h>

#define pinRelay GPIO_NUM_12


class relay
{
public:
    void initRelay();
    void kickrelay(int pin,int state);
    void processor(float *temperature);

};

extern relay _relay;

#include "relay.h"

void relay::initRelay()
{
    pinMode(pinRelay,OUTPUT);
    
}

void relay::kickrelay(int pin,int state)
{
    digitalWrite(pin,state);
}
void relay::processor(float *temperature)
{
    //Serial.printf("temperature:= %2.f\n",*temperature);
    if(*temperature > 40.00)
        kickrelay(pinRelay,1);
    else
        kickrelay(pinRelay,0);
}

relay _relay;
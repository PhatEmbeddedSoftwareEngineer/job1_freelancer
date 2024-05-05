#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/Task.h"
#include "freertos/semphr.h"

class watchDog
{
private:
    uint8_t flag;
    hw_timer_t * timer0=NULL;
    
    uint32_t timeForDogEat=10000000; // 10s

    
public:
    void initWatchDog();
    void choAn();
};

extern watchDog _choCanhEsp32;

#include "watchdog.h"
watchDog _choCanhEsp32;
portMUX_TYPE timerMux=portMUX_INITIALIZER_UNLOCKED;
void IRAM_ATTR reset()
{
    portENTER_CRITICAL_ISR(&timerMux);
    Serial.println("watch dog :(( khoi dong lai");
    esp_restart();
    portEXIT_CRITICAL_ISR(&timerMux);
}


void watchDog::initWatchDog()
{
    timer0=timerBegin(0,80,true);
    timerAttachInterrupt(timer0,&reset,true);
    timerAlarmWrite(timer0,timeForDogEat,true);
    timerAlarmEnable(timer0);
}

void watchDog::choAn()
{
    timerWrite(timer0,0); // cho an 
}
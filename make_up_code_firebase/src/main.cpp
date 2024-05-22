#include <Arduino.h>
#include "firebase.h"
#include "watchdog.h"
#include "fcn_telegram.h"
#include "cambien.h"
#include "bluetooth.h"
#include "relay.h"

/**
 * 
*/

void setup() {
  Serial.begin(115200);
#if 1
  _bluetooth.setup();
  fire.initFirebase();
  fire.setThoiGianCho(5000);
  
  _choCanhEsp32.initWatchDog();
  _sensor.initDHT();

#endif
  _relay.initRelay();

} 

void loop() {
#if 1
  _sensor.loopDHT(&_sensor.temperature,&_sensor.humidity);
  _sensor.getGasSensor(&_sensor.gas);
  _sensor.getKhoiSensor(&_sensor.khoi);

  _relay.processor(&_sensor.temperature);

  // put your main code here, to run repeatedly:
  fire.runFirebase(_sensor.temperature,_sensor.humidity,_sensor.gas,_sensor.khoi);

  //delay(11000);
  _choCanhEsp32.choAn();
  //Serial.println("da cho an");
#endif
  //_relay.kickrelay(pinRelay,1);
  
}


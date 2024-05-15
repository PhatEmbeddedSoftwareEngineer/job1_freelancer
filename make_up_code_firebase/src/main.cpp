#include <Arduino.h>
#include "firebase.h"
#include "watchdog.h"
#include "fcn_telegram.h"
#include "cambien.h"

/**
 * 
*/

void setup() {
  //Serial.begin(115200);
  fire.initFirebase();
  fire.setThoiGianCho(5000);
  
  _choCanhEsp32.initWatchDog();
  _sensor.initDHT();

} 

void loop() {
  _sensor.loopDHT(&_sensor.temperature,&_sensor.humidity);
  _sensor.getGasSensor(&_sensor.gas);

  _sensor.getValue(&_sensor.khoi);
  /**
   * function tele danh cho gia chi cam bien that
  */
  //tele.loopTele(_sensor.nhietdo,_sensor.doam,_sensor.gas,_sensor.khoi);
  /*
  Serial.printf("nhiet do: %d\n",_sensor.nhietdo);
  Serial.printf("do am:= %f\n",_sensor.doam);
  Serial.printf("gas:= %f\n",_sensor.gas);
  Serial.printf("khoi:= %f\n",_sensor.khoi);
  */
  

  // put your main code here, to run repeatedly:
  fire.runFirebase(_sensor.temperature,_sensor.humidity,_sensor.gas,_sensor.khoi);
  
  //delay(11000);
  _choCanhEsp32.choAn();
}


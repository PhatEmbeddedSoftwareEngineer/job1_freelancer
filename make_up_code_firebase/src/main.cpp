#include <Arduino.h>
#include "firebase.h"
#include "watchdog.h"


void setup() {
  fire.initFirebase();
  fire.setThoiGianCho(5000);
  _choCanhEsp32.initWatchDog();

} 

void loop() {
  // put your main code here, to run repeatedly:
  fire.runFirebase();
  //delay(11000);
  _choCanhEsp32.choAn();
}


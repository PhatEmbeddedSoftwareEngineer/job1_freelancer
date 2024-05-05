#include <Arduino.h>
#include "firebase.h"



void setup() {
  fire.initFirebase();
  fire.setThoiGianCho(5000);
} 

void loop() {
  // put your main code here, to run repeatedly:
  fire.runFirebase();
}


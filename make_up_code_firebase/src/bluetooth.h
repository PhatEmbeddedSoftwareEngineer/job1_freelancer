#include <Arduino.h>
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
#include <EEPROM.h>
#include "WiFi.h"


class bluetooth
{
public:
    String buffer_in;
    unsigned long previousMillis = 0; 
    byte val; 
    int addr = 0;
    byte indS=0;
    byte indP=0;
    String stream;
    byte len=0;
    String temp;
    String temp2;
    unsigned int interval=15000; // 15s
    char ssid[50];
    char pass[50];

    void setup();
    boolean check_wifiUpdate();



};

extern bluetooth _bluetooth;


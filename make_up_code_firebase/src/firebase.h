#ifndef FIREBASE_H
#define FIREBASE_H
#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>



// Insert your network credentials
#define WIFI_SSID "Phat1"
#define WIFI_PASSWORD "0937875855"


// Insert Firebase project API Key
#define API_KEY "AIzaSyAseU2XSE3MyNGqizdbipjUdWhUAaa1O00"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://test-7ed86-default-rtdb.asia-southeast1.firebasedatabase.app/" 


class geeks 
{
private:
    FirebaseData fbdo;

    FirebaseAuth auth;
    FirebaseConfig config;
    unsigned long sendDataPrevMillis = 0;
    int count = 0;
    bool signupOK = false;
    unsigned int thoigian_cho;
    uint32_t cnt=0;


public:
    void setThoiGianCho(int s);
    void initFirebase();
    void runFirebase(float nhietdo,float doam,uint32_t gas, uint32_t khoi);

};


extern geeks fire;

#endif


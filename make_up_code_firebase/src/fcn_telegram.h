#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#define BOTtoken "7040537799:AAHbciJh4XykJKqH9s5DpONHa-weC5gcqWA"
#define CHAT_ID "5561587743"
extern WiFiClientSecure client;
extern UniversalTelegramBot bot;

class setupTele
{
private:
    //const char* ssid ;
    //const char* password ;
public:
    uint32_t timeTick=0;
    uint32_t timeWait=1000;
    
    //void init_Wifi();
    //void setupWifi();
    void initTeleGram();
    void sendData(String message);
    void warining(String warining, uint32_t value);
    void loopTele(uint32_t nhietdo, float doam, float gas, float khoi);
};

extern setupTele tele;

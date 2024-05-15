#include "fcn_telegram.h"
setupTele tele;
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setupTele::initTeleGram()
{
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
    Serial.println("khoi tao thanh cong telegram");
}
/**
 * ham nay dung de gui tin nhan den bot tele
*/
void setupTele::sendData(String message)
{
    bot.sendMessage(CHAT_ID, message);
}

/**
 * ham nay dung de gui tin nhan canh bao den bot tele va gia tri vuot nguong canh bao
 * 
*/

void setupTele::warining(String warining, uint32_t value)
{
    char buffer[100];
    sprintf(buffer,"canh bao gia tri vuot nguong := %d !!!!!!!!\n ",value);
    bot.sendMessage(CHAT_ID,buffer);
    bot.sendMessage(CHAT_ID,warining);
    //Serial.printf("",value);
    //Serial.printf("%s\n",warining);
}

void setupTele::loopTele(uint32_t nhietdo, float dodam, float gas, float khoi)
{
    if(millis() - tele.timeTick >= tele.timeWait )
    {
        tele.timeTick = millis();
        if(nhietdo >= 50)
        {
            tele.warining("nhiet do da vuot nguong",nhietdo);
        }
    }
}

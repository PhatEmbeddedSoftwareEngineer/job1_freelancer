#include "cambien.h"
#include "relay.h"
DHTesp dht;

sensor _sensor;

void sensor::getValue(  float *khoi)
{
    *khoi = random(10,100) + 1.235;
}
/**
 * khoi tao cam bien dht22
*/

void sensor::initDHT()
{
    dht.setup(GPIO_Pin,DHTesp::DHT22);
}

/**
 * function main de doc gia tri nhiet do va do am tu cam bien dht22
 * 
*/


void sensor::loopDHT(float *temperature, float *humidity)
{
    uint32_t delaytime;
    delaytime = dht.getMinimumSamplingPeriod();
    //Serial.printf("thoi gian lay mau: %d\n",delaytime);
    /**
     * thoi gian can de lay mau
    */
    //delay(delaytime);

    *temperature=dht.getTemperature();
    *humidity = dht.getHumidity();

    const char* status = dht.getStatusString();
#if 0
    if(strcmp(status,"OK")==0)
        Serial.println("fantastic");
    else
        Serial.println("SOS!!!!!!");
#endif 
    


}

void sensor::getGasSensor(uint32_t *gas)
{
    *gas = analogRead(gasPin);
}

void sensor::getKhoiSensor(uint32_t *khoi)
{
    Serial.printf("khoi:= %d\n",*khoi);
    *khoi = analogRead(khoiPin);
    if(*khoi >= 2800)
    {
        for(int i=0;i<10;i++)
        {
            _relay.kickrelay(pinRelay,1);
            delay(200);
        }
        
    }
        
    else
        _relay.kickrelay(pinRelay,0);
}


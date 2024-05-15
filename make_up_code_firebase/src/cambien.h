#include <Arduino.h>
#include "DHTesp.h"

extern DHTesp dht;

#define GPIO_Pin GPIO_NUM_15


class sensor
{
private:
    const int gasPin = GPIO_NUM_34;
public:
    float humidity;
    float temperature;
    uint32_t gas;
    float khoi;

    void getValue(float *khoi);
    /**
     * khoi tao dht22 sensor 
    */

    void initDHT();

    /**
     * khoi tao function main de doc nhiet do va do am
     * hai ham nay nhan doi la 2 dia chi cua temperature va humidity
    */
    void loopDHT(float *temperature, float *humidity);

    /**
     * functon doc cam bien khi gas ham nay nhan mot doi so la mot dia chi uint32_t gas
    */

    void getGasSensor(uint32_t *gas);

};

extern sensor _sensor;

#include <Arduino.h>
#include "DHTesp.h"

extern DHTesp dht;

/**
 * chan nay giao tiep voi cam bien dht 
*/
#define GPIO_Pin GPIO_NUM_13


class sensor
{
private:
    /**
     * chan nay giao tiep voi cam bien khi gas
    */
    const int gasPin = GPIO_NUM_34;
    /***
     * chan nay giao tiep voi cam bien khoi
    */
    const int khoiPin = GPIO_NUM_35;

public:
    float humidity;
    float temperature;
    uint32_t gas;
    uint32_t khoi;

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

    /**
     * function nay dung de doc gia tri cua cam bien khoi 
    */

    void getKhoiSensor(uint32_t *khoi);

};

extern sensor _sensor;

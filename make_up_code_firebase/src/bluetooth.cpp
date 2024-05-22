#include "bluetooth.h"

BluetoothSerial ESP_BT; //Object for Bluetooth

bool bluetooth::check_wifiUpdate()
{
    /*cap nhat thoi gian hien tai*/
    unsigned long currentMillis = millis();
    /*thoi gian hien tai tru thoi gian truoc do neu lon hon >= 15s thi return true*/

    if (currentMillis - previousMillis >= interval)
    {
        
        previousMillis = currentMillis;
        Serial.println("15 Seconds Over");

        return true;
    }
    //Check if we receive anything from Bluetooth
    /*neu da ket noi bluetooth ban co them 75s de setup wifi va pass*/
    else if(ESP_BT.available())
    {
        interval=75000;
        /**
         * bien buffer_in nay se doc cac chuoi nhan duoc tu bluetooth
        */
        buffer_in = ESP_BT.readStringUntil('\n'); //Read what we recevive 
        delay(20);
        /**
         * tach chuoi neu ky tu dau tien la w
         * thi thuc hien vong lap for chay tu 0->chieu dai cua chuoi
         * 
        */
        // wifi:
        if(buffer_in.charAt(0)=='w')
        {
            for(int i=0;i<buffer_in.length();i++)
            {
                /**
                 * ep kieu toan bo du lieu sang byte va gan vao val
                */
                val=(byte)(buffer_in.charAt(i));
                /**
                 * ghi no vao bo nho eeprom
                */
                EEPROM.write(addr, val);
                addr++;

            }
            /**
             * sau khi ghi xong de nhan biet chuoi nao la wifi chuoi nao la password
             * ta viet them so 10 vao de nhan biet giua 2 chuoi 
            */
            EEPROM.write(addr, 10);
            /**
             * tang len addr++;
            */
            addr++;
            /**
             * ham nay dung commit vao eeprom
            */
            EEPROM.commit();  
            /**
             * in ra trong giao dien bluetooth la da luu tru thanh 
             * cong ten wifi
            */
            ESP_BT.println("WiFi Stored");

        }
        // Pass:
        /**
         * check xem trong chuoi buffer_in nhan duoc co ky tu dau tien la tu
         * p khong
        */
        else if(buffer_in.charAt(0)=='p')
        {

            for(int i=0;i<buffer_in.length();i++)
            {
                val=(byte)(buffer_in.charAt(i));
                EEPROM.write(addr, val);
                addr++;

            }
            EEPROM.write(addr, 10);
            EEPROM.commit();
            ESP_BT.println("Password Stored"); 
            //flag=1;
            /**
             * sau khi hoan tat qua trinh ghi vao eeprom 
             * return true
            */

            return true;
        }
        // neu sau 75s ma khong cap nhat xong ten wifi va mk thi tro lai false

        return false;
    }
    else
    {
        return false;
    }

}

void bluetooth::setup()
{
    /**
     * khoi tao EEPROM voi kich thuoc 50 
    */
    EEPROM.begin(50);
    /**
     * khoi tao ten bluetooth la Badger_Team
    */
    ESP_BT.begin("Badger_TeamZ"); //Name of your Bluetooth Signal
    /**
     * ham nay chi khi cap nhat wifi qua bluetooth or khi qua 15s 
     * thi moi thoat dc vong lap
    */
    while(!check_wifiUpdate()==true);
    /**
     * vong lap for lap qua toan bo du lieu ben trong bo nho
     * EEPROM va gan no vao bien val 
     * 
    */
   for(int i=0;i<50;i++)
    {
        val=EEPROM.read(i);
        /**
         * ep kieu va ghi no vao chuoi stream
         * 
        */
        stream+=(char)val;
        /**
         * tim den diem val ==10 noi danh dau giua wifi va pass 
        */
        if((val==10) && (indS==0))
        {
            /**
             * cap nhat indS =i tai noi do 
            */
            indS=i;
        }
        else if(val==10 && indP==0)
        {
            /**
             * tuong tu voi password ta cung cap nhat sau do 
             * break vong lap
            */
            indP=i;
            break;
        }

    }
    /**
     * dung chuoi temp de ghi chuoi tu 0 den noi cap nhat indS
     * sau do bo ra 5 ky tu dau tien la wifi: de lay ten wifi 
    */
    temp=stream.substring(0,indS);
    temp=temp.substring(5,indS);

    /**
     * tuong tu voi tren ta cong them bien indS+1 va lay den indP
     * sau do ta bo 5 ky tu dau la pass: va lay toan bo pass bang cach dung indP-indS
     * 
    */
    temp2=stream.substring(indS+1,indP);
    temp2=temp2.substring(5,indP-indS);
    /**
     * cap kich thuoc chieu dai cua 2 chuoi la i va j
    */
    int i=temp.length();
    int j=temp2.length();
    _bluetooth.ssid[i];
    _bluetooth.pass[j]; 

    /**
     * sau do chuyen doi tu String thanh char theo cac kich thuoc cua i
     * va kich thuoc cua j
     * de luu ssid va pass 
    */
    temp.toCharArray(_bluetooth.ssid,i);
    temp2.toCharArray(_bluetooth.pass,j);
    Serial.println("Stored Wifi");
    Serial.println(_bluetooth.ssid);
    Serial.println("Stored PASS");
    Serial.println(_bluetooth.pass);

    

}

bluetooth _bluetooth;
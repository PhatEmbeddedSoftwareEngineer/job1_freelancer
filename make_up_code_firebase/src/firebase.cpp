#include "firebase.h"
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
geeks fire;
void geeks::setThoiGianCho(int s)
{
    thoigian_cho=s;
}
void geeks::initFirebase()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(300);
    }
    delay(5000);
    Serial.println("da ket noi duoc wifi");
    /* Assign the api key (required) */
    config.api_key = API_KEY;

    /* Assign the RTDB URL (required) */
    config.database_url = DATABASE_URL;

    /* Sign up */
    if (Firebase.signUp(&config, &auth, "", "")){
        Serial.println("ok");
        signupOK = true;
    }
    else{
        Serial.printf("%s\n", config.signer.signupError.message.c_str());
    }

    if(signupOK)
    {
        delay(5000);
        Serial.println("da ket noi thanh cong firebase");
    }
    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
    
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

void geeks::runFirebase()
{
    if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > thoigian_cho || sendDataPrevMillis == 0))
    {
        sendDataPrevMillis = millis();
        // Write an Int number on the database path test/int
        if (Firebase.RTDB.setInt(&fbdo, "test/int", count)){
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
        }
        else {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
        }
        count++;

        // Write an Float number on the database path test/float
        if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0,100))){
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
        }
        else {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
        }
    }
}
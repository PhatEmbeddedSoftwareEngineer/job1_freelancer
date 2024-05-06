# job1_freelancer
# function firebase and nodejs


Đầu tiền chúng ta nên khởi tạo monitor tức là tốc độ baud ở UART0 mặc đinh của esp32.
* khởi tạo monitor:
```C++
    Serial.begin(115200);
```

* thiết lập kết nối wifi:

```C++
    #define WIFI_SSID "Ten WiFi"
    #define WIFI_PASSWORD "Password"
```

* Để kết nối được wifi ta dùng hàm này:

```C++
void connectWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(300);
        cnt+=1;
        if(cnt==30)
            esp_restart();
    }
    delay(5000);
    Serial.println("da ket noi duoc wifi");
}
```

* Để dùng được firebase ta cần phải có API Key và đường dẫn URL
* Bạn có thể tham khảo đường dẫn sau để lấy được API Key và URL: 
[Link Firebae](https://randomnerdtutorials.com/esp32-firebase-realtime-database/)

Sau khi có được API Key và URL ta sẽ định nghĩa nó trong C++ bằng cách:

```C++
    #define API_KEY "API KEY"

    #define DATABASE_URL "URL" 


```

Để sử dụng Firebase bạn cần có thư viện của Firebase hỗ trợ cho nền tảng Framwork Arduino:

```C++
    #include <Firebase_ESP_Client.h>
```

Nếu bạn dùng Platform IO thì có thể truy cập vào PIO home -> Libraries -> rồi nhập tên thư viện vào 

Nếu bạn dùng Arduino IDE thì bạn có thể tải link này: [Firebase_ESP_Client](https://github.com/mobizt/Firebase-ESP-Client)

* Để dùng được Firebase bạn sẽ cần các tham số như:
```C++
    FirebaseData fbdo;

    FirebaseAuth auth;
    FirebaseConfig config;
```


Để cấu hình cho firebase theo cách như sau:

```C++

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
```

Để đưa dữ liệu lên firebase ta có thể dùng hàm sau:

```C++
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

```




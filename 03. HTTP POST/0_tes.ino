#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
WiFiClient client;

const char* wifi = "DILO3";
const char* pass = "DiloBSD123";

void setup(){
    Serial.begin(115200);
    WiFi.begin(wifi, pass);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println("ESP8266 terhubung ke WiFi!");
}

void uploadData(int suhu, int lembab, int analog){
    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        http.begin("http://nameless-everglades-17984.herokuapp.com/iot");
        http.addHeader("Content-Type", "application/json");
        String body = "{\"suhu\": " + String(suhu) + ", \"lembab\": " + String(lembab) + ", \"analog\": " + String(analog) + "}";
        int httpPost = http.POST(body);
        String payload = http.getString();

        Serial.println(httpPost);
        Serial.println(payload);
        Serial.println(body);
        http.end();
    } else {
        Serial.println("Koneksi terputus!");
    }
    delay(1000);
}

void loop(){
    int suhu = 26;
    int lembab = 11;
    int analog = 1992;
    uploadData(suhu, lembab, analog);
    delay(15000);
}
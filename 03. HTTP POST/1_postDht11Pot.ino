#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
WiFiClient client;

#include "DHT.h"
#define DHTpin D2
#define DHTtype DHT11
DHT dht(DHTpin, DHTtype)

const char* wifi = "DILO3";
const char* pass = "DiloBSD123";

void setup(){
    Serial.begin(115200);
    pinMode(D5, OUTPUT);
    WiFi.begin(wifi, pass);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println("ESP8266 terhubung ke WiFi!");
}

void uploadData(int suhu, int lembab, int analog){
    if(WiFi.status() == WL_CONNECTED){
        digitalWrite(D5, HIGH);
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
    delay(3000);
    digitalWrite(D5, LOW);
}

void loop(){
    int suhu = dht.readTemperature();
    int lembab = dht.readHumidity();
    int analog = analogRead(A0);
    uploadData(suhu, lembab, analog);
    delay(15000);
}
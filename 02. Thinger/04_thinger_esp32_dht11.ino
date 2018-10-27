
// library ESP32
#include <WiFi.h>
#include <ThingerESP32.h>

// initial setup DHT
#include "DHT.h"
#define DHTpin D4
#define DHTtype DHT11
DHT dht(DHTpin, DHTtype)

#define USERNAME "Lintang_Wisesa"
#define DEV_ID "lintang"
#define DEV_CRED "lintang"

#define SSID "DILO3"
#define PASS "DiloBSD123"

ThingerESP32 thing(USERNAME, DEV_ID, DEV_CRED);

void setup(){
    pinMode(D5, OUTPUT);
    dht.begin();
    thing.add_wifi(SSID, PASS);
    thing["led"] << digitalPin(D5);
    thing["pot"] >> outputValue(analogRead(A0));
    thing["shu"] >> outputValue(dht.readTemperature());
    thing["lbb"] >> outputValue(dht.readHumidity());
}

void loop(){
    thing.handle();
}

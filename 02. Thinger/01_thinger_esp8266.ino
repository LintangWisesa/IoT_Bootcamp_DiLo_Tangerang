// library ESP8266
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "Lintang_Wisesa"   // username ada di pojok kanan atas dashboard
#define DEV_ID "lintang"
#define DEV_CRED "lintang"

#define SSID "DILO3"
#define PASS "DiloBSD123"

ThingerESP8266 thing(USERNAME, DEV_ID, DEV_CRED);

void setup(){
    pinMode(D5, OUTPUT);
    thing.add_wifi(SSID, PASS);
    thing["led"] << digitalPin(D5);
    thing["pot"] >> outputValue(analogRead(A0));
}

void loop(){
    thing.handle();
}

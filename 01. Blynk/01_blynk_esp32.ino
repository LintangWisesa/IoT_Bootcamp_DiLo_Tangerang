
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char token[] = "a6e801a2b49243e5a346235ff5c8a003";
char ssidwifi[] = "DILO3";
char passwifi[] = "DiloBSD123";

void setup(){
    Blynk.begin(token, ssidwifi, passwifi);
}

void loop(){
    Blynk.run();
}
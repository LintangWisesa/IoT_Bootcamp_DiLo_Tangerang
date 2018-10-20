
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleTimer.h>  // ambil dari v0.4.6
SimpleTimer timer;

char token[] = "a6e801a2b49243e5a346235ff5c8a003";
char ssidwifi[] = "DILO3";
char passwifi[] = "DiloBSD123";

void bacaDuaKaliPot(){
    int duaPot = 2 * analogRead(A0);
    Blynk.virtualWrite(V1, duaPot);
}

void setup(){
    Blynk.begin(token, ssidwifi, passwifi);
    timer.setInterval(1000L, bacaDuaKaliPot);
}

void loop(){
    Blynk.run();
    timer.run();
}
#include "DHT.h" 
#define DHTPIN D8
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(D5, OUTPUT);
  dht.begin();
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Lembab: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Analog: ");
  Serial.println(analogRead(A0));
  digitalWrite(D5, HIGH);
  delay(1500);
  digitalWrite(D5, LOW);
  delay(1500);
}
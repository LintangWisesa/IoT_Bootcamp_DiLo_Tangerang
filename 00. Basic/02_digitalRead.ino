void setup(){
    Serial.begin(115200);
    pinMode(D3, INPUT);
}

void loop(){
    Serial.println(digitalRead(D3));
    delay(100);  
}
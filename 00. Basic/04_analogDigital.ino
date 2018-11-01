void setup(){
    pinMode(D5, OUTPUT);
}

void loop(){
    analogWrite(D5, analogRead(A0)/4);
}
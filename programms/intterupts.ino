const uint8_t gpioNum = 2 ;

void setup()
{
    //ustawiamy GPIO 2 jako wejście podciągnięte do plusa
    Serial.begin(9600);
    pinMode(gpioNum,INPUT_PULLUP);
}

void loop()
{
    static bool lastValue = 1;
    /*Pooling*/
    bool currentValue = digitalRead(gpioNum);
    if(currentValue == 0 && lastValue ==1){
        /*wystąpił warunek*/
        Serial.println("Warunek spełniony");
    }
    lastValue == currentValue;

}


void ISRfunc()
{
    Serial.println("Warunek spełniony (INT)");
}


void setup()
{
Serial.begin(9600);
pinMode(gpioNum, INPUT_PULLUP);
attachInterrupyz(digitalPinToInterrupt(gpioNum,ISRfunc(),))

}


void loop()
{
    Serial.println("Random print ... ")
    delay(100);
}
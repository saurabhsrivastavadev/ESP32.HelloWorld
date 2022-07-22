#include <Arduino.h>
#include <SerialUtils.h>

void setup() {
    // put your setup code here, to run once:
    SerialUtils::prepareSerial();
}

void loop() {
    // put your main code here, to run repeatedly:
    std::string name = SerialUtils::serialInputBlocking("Your name? ");
    Serial.print("Hello ");
    Serial.println(name.c_str());
    delay(1000);
}
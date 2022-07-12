/**
    SerialUtilsTest.ino
    Created on: 10.Jul.2022

    Serial Port communication utilities.
*/

#include <Arduino.h>
#include <SerialUtils.h>

// SETUP and LOOP
void setup() {
  
  SerialUtils::prepareSerial();
}

void loop() {

  Serial.println("In the loop.");

  SerialUtils::serialInputBlocking("Please type your name: ");

  Serial.println("Going to sleep for 10 seconds..");

  delay(10000);
}

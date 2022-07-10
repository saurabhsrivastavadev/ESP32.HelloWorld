/**
    HelloWorld.ino
    Created on: 10.Jul.2022

    Serial Port communication utilities.
*/

#include <Arduino.h>

void prepareSerial() {

  Serial.begin(115200);
  for (uint8_t i = 0; i < 4; i++) {
    Serial.println();
    Serial.flush();
    delay(1000);
  }
}

// SETUP and LOOP
void setup() {
  
  prepareSerial();
}

void loop() {

  Serial.println("In the loop.");

  if (Serial.available()) {
    Serial.println("Serial available:");
    while (Serial.available()) {
      Serial.print(char(Serial.read()));      
    }
  } else {
    Serial.println("Serial unavailable");
  }

  Serial.println("Going to sleep for 10 seconds..");

  delay(10000);
}

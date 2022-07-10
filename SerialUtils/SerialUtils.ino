/**
    SerialUtils.ino
    Created on: 10.Jul.2022

    Serial Port communication utilities.
*/

#include <Arduino.h>
#include <string>
#include <sstream>

void prepareSerial() {

  Serial.begin(115200);
  delay(1000);
  Serial.print("Preparing Serial.");
  for (uint8_t i = 0; i < 4; i++) {
    Serial.print(".");
    Serial.flush();
    delay(1000);
  }
  Serial.println();
}

// Function to block for serial input 
std::string serialInputBlocking(const std::string& msg, char terminatingChar = '\n') {
  
  Serial.print(msg.c_str());

  char c = '\0';
  std::stringstream ss;

  while (c != terminatingChar) {

    while (!Serial.available()) {
      delay(100);
    }
    c = (char)Serial.read();
    if (c != terminatingChar) {
      ss << c;
      Serial.print(c);      
    }
  }

  Serial.println();
  return ss.str();
}

// SETUP and LOOP
void setup() {
  
  prepareSerial();
}

void loop() {

  Serial.println("In the loop.");

  serialInputBlocking("Please type your name: ");

  Serial.println("Going to sleep for 10 seconds..");

  delay(10000);
}

/*
  SerialUtils.cpp - Library containing Serial utilities.
  Created by me@saurabhsrivastava.dev, July 12, 2022.
  Released into the public domain.
*/

#include <Arduino.h>
#include "SerialUtils.h"

#include <string>
#include <sstream>

void SerialUtils::prepareSerial() {

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
std::string SerialUtils::serialInputBlocking(const std::string& msg, char terminatingChar) {
  
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

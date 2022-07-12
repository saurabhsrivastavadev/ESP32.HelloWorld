/*
  SerialUtils.h - Library containing Serial utilities.
  Created by me@saurabhsrivastava.dev, July 12, 2022.
  Released into the public domain.
*/

#ifndef SerialUtils_h
#define SerialUtils_h

#include <string>
#include <sstream>

class SerialUtils 
{
  public:
    // Block to accept a user input over the serial port 
    static std::string serialInputBlocking(const std::string& msg, char terminatingChar = '\n');

    // Prepare the serial port 
    static void prepareSerial();
};

#endif

/*
 * ArduinoMotionPlus.cpp - Improved Wii Motion Plus library for Arduino
 * 
 * Copyright 2011-2012 Carter Cole, http://www.cartercole.com/
 *
 *
 * Based on the following projects/websites:
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 */

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <Wire.h>
#include "ArduinoMotionPlus.h"

#define ADDRESS 0x52

void ArduinoMotionPlus::init()
{      
  Wire.begin();
  
  ArduinoMotionPlus::_sendByte(0x55, 0xF0);
  ArduinoMotionPlus::_sendByte(0x00, 0xFB); 
  
  ArduinoMotionPlus::update();
}
    
void ArduinoMotionPlus::update()
{ 
  int count = 0;      
  int values[5];
  
  Wire.requestFrom (ADDRESS, 6); 
  
  while(Wire.available())
  {
    values[count] = Wire.read();
    count++;
  } 
  
  ArduinoNunchuk::analogX = values[0];
  ArduinoNunchuk::analogY = values[1];      
  ArduinoNunchuk::accelX = values[2] * 2 * 2 + ((values[5] >> 2) & 1) * 2 + ((values[5] >> 3) & 1);
  ArduinoNunchuk::accelY = values[3] * 2 * 2 + ((values[5] >> 4) & 1) * 2 + ((values[5] >> 5) & 1);
  ArduinoNunchuk::accelZ = values[4] * 2 * 2 + ((values[5] >> 6) & 1) * 2 + ((values[5] >> 7) & 1);
  ArduinoNunchuk::zButton = !((values[5] >> 0) & 1);
  ArduinoNunchuk::cButton = !((values[5] >> 1) & 1);
  
  ArduinoNunchuk::_sendByte(0x00, 0x00);
}
  
void ArduinoMotionPlus::_sendByte(byte data, byte location)
{  
  Wire.beginTransmission(ADDRESS);
  
  #if (ARDUINO >= 100)
    Wire.write(location);
    Wire.write(data);  
  #else
    Wire.send(location);
    Wire.send(data); 
  #endif
  
  Wire.endTransmission();
  
  delay(10);
}

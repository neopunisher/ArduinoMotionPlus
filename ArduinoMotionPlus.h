/*
 * ArduinoMotionPlus.h - Improved Wii Motion Plus library for Arduino
 * 
 * Copyright 2011-2012 Carter Cole, http://www.cartercole.com/
 *
 *
 * Based on the following projects/websites:
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 */
#ifndef ArduinoMotionPlus_H
#define ArduinoMotionPlus_H

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class ArduinoMotionPlus
{  
  public:  
    int yaw;
    int pitch;
    int roll;
  
    void init();    
    void update();
    
  private:  
    int yaw0;
    int pitch0;
    int roll0;
  
    void _sendByte(byte data, byte location);
};

#endif

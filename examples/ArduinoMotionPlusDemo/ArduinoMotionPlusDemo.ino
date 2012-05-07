/*
 * ArduinoMotionPlus Demo
 * 
 * Copyright 2011-2012 Carter Cole, http://www.cartercole.com/
 *
 * 
 */

#include <Wire.h>
#include <ArduinoMotionPlus.h>

#define BAUDRATE 19200

ArduinoMotionPlus motionplus = ArduinoMotionPlus();

void setup()
{
  Serial.begin(BAUDRATE);
  motionplus.init();
}

void loop()
{
  motionplus.update();
  
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
}

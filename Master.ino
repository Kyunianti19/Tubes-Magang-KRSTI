// Wire Master Writer

#include <Wire.h>
#include "HEADER.h"

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
}

void loop() 
{
  while(Serial.available())
  {
    String c = Serial.readString();
    if (c == "Onn")
    {
      Wire.beginTransmission(7);
      Wire.write('H');
      Wire.endTransmission();
    }
    else if (c == "Off")
    {
      Wire.beginTransmission(7);
      Wire.write('L');
      Wire.endTransmission(); 
    } else if ((isDelay(c))||((c[0]=='d')&&(c[1]==' ')))
    {
      int delayLed = ParseDelay(c);
      Wire.beginTransmission(7);
      Wire.write('D');
      Wire.write(delayLed);
      Wire.endTransmission(); 
    }
    
    Serial.println(c);
  }
}

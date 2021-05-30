/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Addition to original blink sketch also turns on and off camera 1's tally indicator.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.
*/

#include <BMDSDIControl.h>                                // need to include the library

BMD_SDITallyControl_I2C sdiTallyControl(0x6E);            // define the Tally object using I2C using the default shield address
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;
// the setup function runs once when you press reset or power the board
void setup()
{
  sdiTallyControl.begin();                                 // initialize tally control
  sdiTallyControl.setOverride(true);                       // enable tally override
  
  pinMode(13, OUTPUT);
  // initialize digital pin 13 as an output

  Wire.begin();         
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.set400kHz();  
  oled.setFont(Adafruit5x7);  

  oled.clear();  
  
}

// the loop function runs over and over again forever
void loop()
{
  byte data[255];
  int retval;
  int a;
  int pierwsza = 0;
  retval = sdiTallyControl.read(data, 255);
  if (retval > 0) {
    
//    if (pierwsza != data[0])
    {
      oled.setCursor(0,0);
      for (a = 0; a < 4; a++)
      {
          oled.set2X();
        oled.print(data[a]);

      }
      oled.println();
    }
//    pierwsza = data[0];
  sdiTallyControl.write(data,retval);
  }
  
}

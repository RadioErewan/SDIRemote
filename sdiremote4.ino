/*  SDI REMOTE skeleton build
    Version 0.2.0.1
    Release date 2017.05.23
    (c) 2017 Radosław Przybył
    http://sdiremote.com
*/



//**** SDI Shield setup
#include <BMDSDIControl.h>
#define __FIRST__
const int                shieldAddress = 0x6E;
BMD_SDICameraControl_I2C sdiCameraControl(shieldAddress);


/*//**** OLED Setup
  // 0X3C+SA0 - 0x3C or 0x3D
  #define I2C_ADDRESS 0x3C
  #include <Wire.h>
  #include "SSD1306Ascii.h"
  #include "SSD1306AsciiAvrI2c.h"
  // #include "SSD1306AsciiWire.h"
  // #define OPTIMIZE_I2C 1
  //SSD1306AsciiWire oled;
  //SSD1306AsciiAvrI2c oled; */
#define ringPIN 6
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
Adafruit_NeoPixel aStrip = Adafruit_NeoPixel(24, ringPIN, NEO_GRB + NEO_KHZ800);

#define I2C_ADDRESS 0x3C
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#define OPTIMIZE_I2C 1
SSD1306AsciiWire oled;

//SSD1306AsciiWire oled;
#define PIN 6

#include <EEPROM.h>


#define STEPS  24   // Number of steps for one revolution of Internal shaft
//Callback
typedef void (*GeneralMessageFunction) ();

#define buildNo "Version RC1.0"

#define isoBase 2500

#define focus 0
#define autoFocus 1
#define aperture 2
#define autoAe 3
#define zoom 4
#define zoomDir 5
#define gain 6
#define whiteBallance 7
#define shutterSpeed 8

#define liftR 24
#define liftG 25
#define liftB 26
#define liftL 27
#define gammaR 29
#define gammaG 30
#define gammaB 31
#define gammaL 32
#define gainR 34
#define gainG 35
#define gainB 36
#define gainL 37
#define offsetR 39
#define offsetG 40
#define offsetB 41
#define offsetL 42

#define contrastPiv 44
#define contrastAdj 45
#define lumaMix 49
#define hsHue 47
#define hsSat 48

#define colorReset 15

#define oIs 51
#define drMode 52
#define sharpening 53

#define frameRate 17


#define audioInput 55
#define audioLvlA 56
#define audioLvlB 57
#define audioPhantom 58

#define seqModeFrom 60
#define seqModeTo 61
#define  seqModeHours 62
#define  seqModeMinutes 63
#define  seqModeSeconds 64


#define seqModeStart 65

#define save 20
#define load 21
#define resetAlldef 99
#define updateAlldef 22
#define cameraId 94

#define bootLoading 96
#define bootUpdate 97
#define sleepDelayId 98

#define saveSize 94
#define maxFirstRowEntries 23
#define settingsStart 94
#define settingsEnd 98

#define defaultsNumber 70

byte cameraDefaults[defaultsNumber] = {
  0,// 00 focus - fixed
  0,// 01 inst AF - 6
  0,// 02 aperture - fixed
  0,// 03 inst AE - 6
  0,// 04 Zoom - fixed
  50,// 05 Zoom speed - fixed
  1,// 06 Sensor gain - int8 1x,2x,4x,8x,16x
  0,// 07 White Balance 2500-8000
  10,// 08 Exposure - 0 do n
  0,// 09 Color lift
  0,// 10 Color lift R
  0,// 11 Color lift R
  0,// 12 Color lift R
  0,// 13 Color lift R
  0,// 14 Color lift R
  0,// 15 Color reset
  0,// 16 Color lift R
  3,// 17 Frame rate - enum 24, 25, 30, 50, 60
  0,// 18 Color lift R
  0,// 19 Sequencer submenu
  0,// 20 Save
  0,// 21 Load
  0,// 22 Update all
  0,// 23
  100,// 24 Color lift R
  100,// 25 Color lift G
  100,// 26 Color lift B
  100,// 27 Color lift L
  0,// 28
  100,// 29 Color gamma R
  100,// 30 Color gamma G
  100,// 31 Color gamma B
  100,// 32 Color gamma L
  0,// 33
  16,// 34 Color gain R ***
  16,// 35 Color gain G
  16,// 36 Color gain B
  16,// 37 Color gain L
  0,// 38
  100,// 39 Color offset R
  100,// 40 Color offset G
  100,// 41 Color offset B
  100,// 42 Color offset L
  0,// 43
  100,// 44 Contrast pivot
  100,// 45 Contrast adj
  0,// 46
  100,// 47 Hue
  100,// 48 Saturation
  10,// 49 Luma mix
  0,// 50
  0,// 51 OIS - boolean
  1,// 52 Dynamic range 0- film, 1-video
  0,// 53 Sharpening 0-off, 1-low, 2-medium, 3-high
  0,// 54
  0,// 55 Audio Input type 0-internal mic, 1-line, 2-low mic, 3-high mic
  50,// 56 Audio lvl ch0 0-1
  50,// 57 Audio lvl ch1 0-1
  0,// 58 Phantom power (true - powered, false - not powered
  0,// 59
  0,// 60 Sequencer from
  1,// 61 Sequencer to
  0,// 62 Sequencer time
  0,// 63 Sequencer time
  10,// 64 Sequencer time
  1,// 94 Camera Id
  0,// 95 settings menu
  5,// 96 settings misc
  0,// 97 settings menu
  2,// 98 settings misc
};



struct cameraSettings
{
  String menuName;
  int numValues;
  int curValue;
  int typeValue;
  int bitmaskValue;  //hsb - value group lsb - value index
  int baseValue;
  byte mulValue;
  bool rotateValue;
  byte reference;

};

struct serialNo
{
  byte batch;
  byte item;
  byte crc;
};


cameraSettings camParams [159] = {

  {"Focus",          100,  0,   0,    0,     0,   1,  0, 0},  // 00 focus - fixed
  {"Instant AF",       0,  0,   6,    1,     0,   0,  0, 90}, // 01 inst AF - 6
  {"Aperture",        30,  0,   0,    3,     0,   1,  0, 0},  // 02 aperture - fixed
  {"Instant AE",       0,  0,   6,    5,     0,   0,  0, 90}, // 03 inst AE - 6
  {"Zoom",           100,  0,   0,    8,     0,   1,  0, 0},  // 04 Zoom - fixed
  {"Zoom direction", 100, 50,   0,    9,     0,   1,  0, 0},  // 05 Zoom speed - fixed
  {"Gain",             4,  1,  11,  257,     0,   0,  0, 67}, // 06 Sensor gain - int8 1x,2x,4x,8x,16x
  {"WB",              55,  0,   3,  258,  2500, 100,  0, 0},  // 07 White Balance 2500-8000
  {"Shutter",         14,  10,  3,  262,     0,   1,  0, 122},// 08 Exposure - 0 do n
  {"Color lift",       4,   0, 99,    0,     0,   0,  1, 24}, // 09 Color lift
  {"Color gamma",      4,   0, 99,     0,    0,   0,  1, 29}, // 10 Color lift R
  {"Color gain",       4,   0, 99,    0,     0,   0,  1, 34}, // 11 Color lift R
  {"Color offset",     4,   0, 99,    0,     0,   0,  1, 39}, // 12 Color lift R
  {"Contrast",         2,   0, 99,    0,     0,   0,  1, 44}, // 13 Color lift R
  {"Hue/sat/luma",     3,   0, 99,    0,     0,   0,  1, 47}, // 14 Color lift R

  {"Color reset",      0,   0, 20,  2055,    0,   0,  0, 91}, // 15 Color reset
  {"Misc",             3,   0, 99,    0,     0,   0,  1, 51}, // 16 Color lift R

  {"Video mode",      21,   3, 97,   256,    0,   0,  1, 137},// 17 Frame rate - enum 24, 25, 30, 50, 60
  {"Audio",            4,   0, 99,    0,     0,   0,  1, 55}, // 18 Color lift R

  {"Sequencer",        6,   0, 99,     1,    0,   0,  1, 60},// 19 Sequencer submenu
  {"Save",             5,   0, 21,     1,    0,   0,  1, 84}, // 20 Save
  {"Load",             5,   0, 22,     1,    0,   0,  1, 84}, // 21 Load
  {"Update all",       1,   0, 23,     1,    0,   0,  0, 92},//  22 Update all
  {"Settings",         7,   0, 99,     1,    0,   0,  1, 94}, // 23


  {"Red",            200, 100, 13,  2048,   -2,   4,  0, 0},  // 24 Color lift R
  {"Green",          200, 100, 13,  2048,   -2,   4,  0, 0},  // 25 Color lift G
  {"Blue",           200, 100, 13,  2048,   -2,   4,  0, 0},  // 26 Color lift B
  {"Luma",           200, 100, 13,  2048,   -2,   4,  0, 0},  // 27 Color lift L
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 28}, // 28


  {"Red",            200, 100, 14,  2049,   -4,   8,  0, 0},  // 29 Color gamma R
  {"Green",          200, 100, 14,  2049,   -4,   8,  0, 0},  // 30 Color gamma G
  {"Blue",           200, 100, 14,  2049,   -4,   8,  0, 0},  // 31 Color gamma B
  {"Luma",           200, 100, 14,  2049,   -4,   8,  0, 0},  // 32 Color gamma L
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 33}, // 33


  {"Red",            256, 16,  15,  2050,    0,  16,  0, 0},  // 34 Color gain R ***
  {"Green",          256, 16,  15,  2050,    0,  16,  0, 0},  // 35 Color gain G
  {"Blue",           256, 16,  15,  2050,    0,  16,  0, 0},  // 36 Color gain B
  {"Luma",           256, 16,  15,  2050,    0,  16,  0, 0},  // 37 Color gain L
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 38}, // 38


  {"Red",            200, 100, 16,  2051,   -8,  16,  0, 0},  // 39 Color offset R
  {"Green",          200, 100, 16,  2051,   -8,  16,  0, 0},  // 40 Color offset G
  {"Blue",           200, 100, 16,  2051,   -8,  16,  0, 0},  // 41 Color offset B
  {"Luma",           200, 100, 16,  2051,   -8,  16,  0, 0},  // 42 Color offset L
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 43}, // 43


  {"Pivot",          200, 100, 17,  2052,    0,   1,  0, 0},  // 44 Contrast pivot
  {"Adjustment",     200, 100, 17,  2052,    0,   2,  0, 0},  // 45 Contrast adj
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 46}, // 46


  {"Hue",            200, 100, 18,  2054,   -1,   2,  0, 0},  // 47 Hue
  {"Saturation",     200, 100, 18,  2054,    0,   2,  0, 0},  // 48 Saturation
  {"Luma mix",       200, 10,   0,  2053,    0,   1,  0, 0},  // 49 Luma mix
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 50}, // 50


  {"OIS",              1,   0,  1,     6,    0,   0,  1, 82}, // 51 OIS - boolean
  {"DR Mode",          1,   1,  4,   263,    0,   0,  1, 72}, // 52 Dynamic range 0- film, 1-video
  {"Detail",           3,   0,  4,   264,    0,   0,  1, 74}, // 53 Sharpening 0-off, 1-low, 2-medium, 3-high
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 54}, // 54


  {"Input type",       3,   0,  4,   516,    0,   0,  1, 78}, // 55 Audio Input type 0-internal mic, 1-line, 2-low mic, 3-high mic
  {"Level ch0",      100,  50, 12,   517,    0,   1,  0, 0},  // 56 Audio lvl ch0 0-1
  {"Level ch1",      100,  50, 12,   517,    0,   1,  0, 0},  // 57 Audio lvl ch1 0-1
  {"Phantom power",    1,   0,  1,   518,    0,   0,  1, 82}, // 58 Phantom power (true - powered, false - not powered
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 59}, // 59

  {"From",             5,   0, 30,     1,    0,   0,  1, 84}, // 60 Sequencer from
  {"To",               5,   1, 31,     1,    0,   0,  1, 84}, // 61 Sequencer to
  {"Hours",           23,    0, 32,     1,    0,   0,  1, 0}, // 62 Sequencer time
  {"Minutes",         59,    0, 32,     1,    0,   0,  1, 0}, // 63 Sequencer time
  {"Seconds",         59,   10, 32,     1,    0,   0,  1, 0}, // 64 Sequencer time

  {"Start",            1,   0, 33,     1,    0,   0,  0, 65}, // 65 Sequencer start
  {"Exit",             0,   0, 34,     1,    0,   1,  1, 66}, // 66

  {"1x",               0,   0,  0,     0,    0,   0,  0, 0},  // 67 gain prams
  {"2x",               0,   0,  0,     0,    0,   0,  0, 0},  // 68 gain prams
  {"4x",               0,   0,  0,     0,    0,   0,  0, 0},  // 69 gain prams
  {"8x",               0,   0,  0,     0,    0,   0,  0, 0},  // 70 gain prams
  {"16x",              0,   0,  0,     0,    0,   0,  0, 0},  // 71 gain prams
  {"film",             0,   0,  0,     0,    0,   0,  0, 0},  // 72 dr prams
  {"video",            0,   0,  0,     0,    0,   0,  0, 0},  // 73 dr prams
  {"off",              0,   0,  0,     0,    0,   0,  0, 0},  // 74 sharpness prams
  {"low",              0,   0,  0,     0,    0,   0,  0, 0},  // 75 sharpness prams
  {"medium",           0,   0,  0,     0,    0,   0,  0, 0},  // 76 sharpness prams
  {"high",             0,   0,  0,     0,    0,   0,  0, 0},  // 77 sharpness prams
  {"internal",         0,   0,  0,     0,    0,   0,  0, 0},  // 78 audio input type params
  {"line",             0,   0,  0,     0,    0,   0,  0, 0},  // 79 audio input type params
  {"low mic",          0,   0,  0,     0,    0,   0,  0, 0},  // 80 audio input type params
  {"high mic",         0,   0,  0,     0,    0,   0,  0, 0},  // 81 audio input type params
  {"off",              0,   0,  0,     0,    0,   0,  0, 0},  // 82 audio phantom params
  {"on",               0,   0,  0,     0,    0,   0,  0, 0},  // 83 audio phantom params
  {"Bank 1",           0,   0,  0,     0,    0,   0,  0, 0},  // 84, 43 banks
  {"Bank 2",           0,   0,  0,     0,    0,   0,  0, 0},  // 85, 43 banks
  {"Bank 3",           0,   0,  0,     0,    0,   0,  0, 0},  // 86, 43 banks
  {"Bank 4",           0,   0,  0,     0,    0,   0,  0, 0},  // 87, 43 banks
  {"Bank 5",           0,   0,  0,     0,    0,   0,  0, 0},  // 88, 43 banks
  {"Cancel",           0,   0,  0,     0,    0,   0,  0, 0},  // 89, 43 banks
  {"Activate",         0,   0,  0,     0,    0,   0,  0, 0},  // 90 misc
  {"Reset",            0,   0,  0,     0,    0,   0,  0, 0},  // 91 misc
  {"Update",           0,   0,  0,     0,    0,   0,  0, 0},  // 92 misc
  {"Start",            0,   0,  0,     0,    0,   0,  0, 0},  // 93 misc

  {"Camera Id",      255,   1,  0,     1,    0,   1,  1, 0},  // 94 Camera Id
  {"Camera model",     5,   0, 51,     1,    0,   1,  1, 103},// 95 settings menu
  {"Boot loading",     5,   5, 52,     1,    0,   1,  1, 109},// 96 settings misc
  {"Auto update",      1,   0, 50,     1,    0,   1,  1, 82}, // 97 settings menu
  {"Sleep delay",      4,   2, 53,     1,    0,   1,  1, 115},// 98 settings misc
  {"Reset all",        1,   0, 24,     1,    0,   0,  0, 99}, // 99 Reset
  {"Info",             0,   0, 54,     1,    0,   1,  1, 120},// 100 settings misc
  {"Save/Exit",        0,   0, 55,     1,    0,   1,  1, 121},// 101 settings
  {"Exit",             0,   0,  0,     1,    0,   1,  1, 0},  // 102
  {"Studio",           0,   0,  0,     1,    0,   1,  1, 0},  // 103 Camera set
  {"Studio 4K",        0,   0,  0,     1,    0,   1,  1, 0},  // 104 Camera set
  {"Micro",            0,   0,  0,     1,    0,   1,  1, 0},  // 105 Camera set
  {"Ursa mini",        0,   0,  0,     1,    0,   1,  1, 0},  // 106 Camera set
  {"Ursa mpro",        0,   0,  0,     1,    0,   1,  1, 0},  // 107 Camera set
  {"Any",              0,   0,  0,     1,    0,   1,  1, 0},  // 108 Camera set
  {"Bank 1",           0,   0,  0,     0,    0,   0,  0, 0},  // 109 Bank Set
  {"Bank 2",           0,   0,  0,     0,    0,   0,  0, 0},  // 110 Bank Set
  {"Bank 3",           0,   0,  0,     0,    0,   0,  0, 0},  // 111 Bank Set
  {"Bank 4",           0,   0,  0,     0,    0,   0,  0, 0},  // 112 Bank Set
  {"Bank 5",           0,   0,  0,     0,    0,   0,  0, 0},  // 113 Bank Set
  {"None",             0,   0,  0,     0,    0,   0,  0, 0},  // 114 Bank Set
  {"1 minute",         0,   0,  0,     1,    0,   1,  1, 0},  // 115 Sleep set
  {"2 minutes",        0,   0,  0,     1,    0,   1,  1, 0},  // 116 Sleep set
  {"10 minutes",       0,   0,  0,     1,    0,   1,  1, 0},  // 117 Sleep set
  {"30 minutes",       0,   0,  0,     1,    0,   1,  1, 0},  // 118 Sleep set
  {"never",            0,   0,  0,     1,    0,   1,  1, 0},  // 119 Sleep set
  {"Info",             0,   0,  0,     1,    0,   1,  1, 0},  // 120
  {"Exit",             0,   0,  0,     1,    0,   1,  1, 0},  // 121
  {"1/2000",           0,   0,  0,     0,    0,   0,  0, 0},  // 122 Shutter
  {"1/1450",           0,   0,  0,     0,    0,   0,  0, 0},  // 123 Shutter
  {"1/1000",           0,   0,  0,     0,    0,   0,  0, 0},  // 124 Shutter
  {"1/725",            0,   0,  0,     0,    0,   0,  0, 0},  // 125 Shutter
  {"1/500",            0,   0,  0,     0,    0,   0,  0, 0},  // 126 Shutter
  {"1/360",            0,   0,  0,     0,    0,   0,  0, 0},  // 127 Shutter
  {"1/250",            0,   0,  0,     0,    0,   0,  0, 0},  // 128 Shutter
  {"1/180",            0,   0,  0,     0,    0,   0,  0, 0},  // 129 Shutter
  {"1/150",            0,   0,  0,     0,    0,   0,  0, 0},  // 130 Shutter
  {"1/120",            0,   0,  0,     0,    0,   0,  0, 0},  // 131 Shutter
  {"1/100",            0,   0,  0,     0,    0,   0,  0, 0},  // 132 Shutter
  {"1/90",             0,   0,  0,     0,    0,   0,  0, 0},  // 133 Shutter
  {"1/75",             0,   0,  0,     0,    0,   0,  0, 0},  // 134 Shutter
  {"1/60",             0,   0,  0,     0,    0,   0,  0, 0},  // 135 Shutter
  {"1/50",             0,   0,  0,     0,    0,   0,  0, 0},  // 136 Shutter

  {"720p50",           0,   0,  0,     0,   50,   2,  0, 0},  // 137 Resolutions
  {"720p59.94",        0,   0,  0,     0,   60,   2,  0, 0},  // 138 Resolutions
  {"720p60",           0,   0,  0,     0,   60,   2,  0, 0},  // 139 Resolutions
  {"1080p23.98",       0,   0,  0,     0,   24,   3,  0, 0},  // 140 Resolutions
  {"1080p24",          0,   0,  0,     0,   24,   3,  0, 0},  // 141 Resolutions
  {"1080p25",          0,   0,  0,     0,   25,   3,  0, 0},  // 142 Resolutions
  {"1080p29.97",       0,   0,  0,     0,   30,   3,  0, 0},  // 143 Resolutions
  {"1080p30",          0,   0,  0,     0,   30,   3,  0, 0},  // 144 Resolutions
  {"1080p50",          0,   0,  0,     0,   50,   3,  0, 0},  // 145 Resolutions
  {"1080p59.94",       0,   0,  0,     0,   60,   3,  0, 0},  // 146 Resolutions
  {"1080p60",          0,   0,  0,     0,   60,   3,  0, 0},  // 147 Resolutions
  {"1080i50",          0,   0,  0,     0,   50,   3,  1, 0},  // 148 Resolutions
  {"1080i59.94",       0,   0,  0,     0,   60,   3,  1, 0},  // 149 Resolutions
  {"1080i60",          0,   0,  0,     0,   60,   3,  1, 0},  // 150 Resolutions
  {"2160p23.98",       0,   0,  0,     0,   24,   4,  0, 0},  // 151 Resolutions
  {"2160p24",          0,   0,  0,     0,   24,   4,  0, 0},  // 152 Resolutions
  {"2160p25",          0,   0,  0,     0,   25,   4,  0, 0},  // 153 Resolutions
  {"2160p29.97",       0,   0,  0,     0,   30,   4,  0, 0},  // 154 Resolutions
  {"2160p30",          0,   0,  0,     0,   30,   4,  0, 0},  // 155 Resolutions
  {"2160p50",          0,   0,  0,     0,   50,   4,  0, 0},  // 156 Resolutions
  {"2160p59.94",       0,   0,  0,     0,   60,   4,  0, 0},  // 157 Resolutions
  {"2160p60",          0,   0,  0,     0,   60,   4,  0, 0},  // 158 Resolutions

};

/*
  {"720p50",           0,   0,  0,     0,    0,   0,  0, 0},  // 145 Resolutions                                        145
  {"720p59.94",        0,   0,  0,     0,    0,   0,  0, 0},  // 146 Resolutions
  {"720p60",           0,   0,  0,     0,    0,   0,  0, 0},  // 147 Resolutions
  {"1080p23.98",       0,   0,  0,     0,    0,   0,  0, 0},  // 148 Resolutions
  {"1080p24",          0,   0,  0,     0,    0,   0,  0, 0},  // 149 Resolutions
  {"1080p25",          0,   0,  0,     0,    0,   0,  0, 0},  // 150 Resolutions                                        150
  {"1080p29.97",       0,   0,  0,     0,    0,   0,  0, 0},  // 151 Resolutions
  {"1080p30",          0,   0,  0,     0,    0,   0,  0, 0},  // 152 Resolutions
  {"1080p50",          0,   0,  0,     0,    0,   0,  0, 0},  // 153 Resolutions
  {"1080p59.94",       0,   0,  0,     0,    0,   0,  0, 0},  // 154 Resolutions
  {"1080p60",          0,   0,  0,     0,    0,   0,  0, 0},  // 155 Resolutions                                        155
  {"1080i50",          0,   0,  0,     0,    0,   0,  0, 0},  // 156 Resolutions
  {"1080i59.94",       0,   0,  0,     0,    0,   0,  0, 0},  // 157 Resolutions
  {"1080i60",          0,   0,  0,     0,    0,   0,  0, 0},  // 158 Resolutions
  {"2160p23.98",       0,   0,  0,     0,    0,   0,  0, 0},  // 159 Resolutions
  {"2160p24",          0,   0,  0,     0,    0,   0,  0, 0},  // 160 Resolutions                                        160
  {"2160p25",          0,   0,  0,     0,    0,   0,  0, 0},  // 161 Resolutions
  {"2160p29.97",       0,   0,  0,     0,    0,   0,  0, 0},  // 162 Resolutions
  {"2160p30",          0,   0,  0,     0,    0,   0,  0, 0},  // 163 Resolutions
  {"2160p50",          0,   0,  0,     0,    0,   0,  0, 0},  // 164 Resolutions
  {"2160p59.94",       0,   0,  0,     0,    0,   0,  0, 0},  // 165 Resolutions                                        165
  {"2160p60",          0,   0,  0,     0,    0,   0,  0, 0},  // 166 Resolutions                                        166
   720p50,


  720p59.94,
  720p60,
  1080p23.98,
  1080p24,
  1080p25,
  1080p29.97,
  1080p30,
  1080p50,
  1080p59.94,
  1080p60,
  1080i50,
  1080i59.94
  1080i60
  2160p23.98,
  2160p24,
  2160p25,
  2160p29.97,
  2160p30,
  2160p50,
  2160p59.94
  2160p60
*/

void setFixed16 (int camera, int category, int paramNo, int paramVal, int paramMax, int base, int multiplier)
{
  float scaledValue;

  scaledValue = base + float(paramVal) / float(paramMax) * multiplier;
  // Serial.println(scaledValue);
  sdiCameraControl.writeCommandFixed16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledValue
  );

}


void setInt16 (int camera, int category, int paramNo, int paramVal, int paramMax, int base, int multiplier)
{
  int scaledValue;

  scaledValue = int(base + paramVal * multiplier);
  sdiCameraControl.writeCommandInt16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledValue
  );
}


void setInt8 (int camera, int category, int paramNo, int paramVal)
{

  sdiCameraControl.writeCommandInt8(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    paramVal
  );

}

void setBoolean (int camera, int category, int paramNo, int paramVal)
{

  sdiCameraControl.writeCommandBool(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    byte (paramVal)
  );

}

void setVoid (int camera, int category, int paramNo)
{
  sdiCameraControl.writeCommandInt16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    0
  );
  //!  exitToTop();

}


void setVideoMode (int camera, int category, int paramNo, int paramVal)
{
  int8_t paramTable[5];
  int const settingsOffset = 137;

  paramTable[0] = int8_t(camParams[settingsOffset + paramVal].baseValue);//frame rate
  paramTable[1] = int8_t(0); ///mrate
  paramTable[2] = int8_t(camParams[settingsOffset + paramVal].mulValue); //resolution
  paramTable[3] = int8_t(camParams[settingsOffset + paramVal].rotateValue); //interlaced 0 progressive
  paramTable[4] = int8_t(0);



  //Disabled temporarily - not working
  sdiCameraControl.writeCommandInt8(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    paramTable
  );

}

void setGain (int camera, int category, int paramNo, int paramVal)
{
  int scaledVal;
  switch (paramVal) {
    case 0:
      scaledVal = 1;
      break;
    case 1:
      scaledVal = 2;
      break;
    case 2:
      scaledVal = 4;
      break;
    case 3:
      scaledVal = 8;
      break;
    case 4:
      scaledVal = 16;
      break;
    default:
      scaledVal = paramVal;
      break;
  }
  // Serial.println (String(camera) + " " + String(category) + " " + String(paramNo) + " " + String(scaledVal));
  sdiCameraControl.writeCommandInt8(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledVal
  );
}
void setAudioLvl (int camera, int category, int paramNo)
{
  float scaledValue;
  float scaledTable[2];

  int paramMax = camParams[audioLvlA].numValues;
  int base = camParams[audioLvlA].baseValue;
  int multiplier = camParams[audioLvlA].mulValue;
  int paramVal = camParams[audioLvlA].curValue;
  scaledValue = base + float(paramVal) / float(paramMax) * multiplier;

  scaledTable[0] = scaledValue;

  paramMax = camParams[audioLvlB].numValues;
  base = camParams[audioLvlB].baseValue;
  multiplier = camParams[audioLvlB].mulValue;
  paramVal = camParams[audioLvlB].curValue;
  scaledValue = base + float(paramVal) / float(paramMax) * multiplier;

  scaledTable[1] = scaledValue;

  scaledValue = base + float(paramVal) / float(paramMax) * multiplier;
  sdiCameraControl.writeCommandFixed16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledTable
  );

}


void setQuadruple (int camera, int category, int paramNo, int startNo)
{
  float scaledValue;
  float scaledTable[4];
  int paramMax;
  int base;
  int multiplier;
  int paramVal;

  for (int i = 0; i < 4; i++) {
    paramMax = camParams[startNo + i].numValues;
    base = camParams[startNo + i].baseValue;
    multiplier = camParams[startNo + i].mulValue;
    paramVal = camParams[startNo + i].curValue;
    scaledValue = base + float(paramVal) / float(paramMax) * multiplier;

    scaledTable[i] = scaledValue;
  }

  sdiCameraControl.writeCommandFixed16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledTable
  );

}

void setDouble (int camera, int category, int paramNo, int startNo)
{
  float scaledValue;
  float scaledTable[2];
  int paramMax;
  int base;
  int multiplier;
  int paramVal;

  for (int i = 0; i < 2; i++) {
    paramMax = camParams[startNo + i].numValues;
    base = camParams[startNo + i].baseValue;
    multiplier = camParams[startNo + i].mulValue;
    paramVal = camParams[startNo + i].curValue;
    scaledValue = base + float(paramVal) / float(paramMax) * multiplier;

    scaledTable[i] = scaledValue;
  }

  sdiCameraControl.writeCommandFixed16(
    camera,         // Destination:    Camera 1
    category,       // Category:       Lens
    paramNo,        // Param:          Zoom (Normalised)
    0,              // Operation:      Assign Value
    scaledTable
  );

}



/*
  void setQuadruple (int camera, int category, int paramNo, int startNo);
  void setAudioLvl (int camera, int category, int paramNo);
  void setDouble (int camera, int category, int paramNo, int startNo);
  void setGain (int camera, int category, int paramNo, int paramVal);
  void setVideoMode (int camera, int category, int paramNo, int paramVal);
  void setVoid (int camera, int category, int paramNo);
  void setBoolean (int camera, int category, int paramNo, int paramVal);
  void setInt8 (int camera, int category, int paramNo, int paramVal);
  void setInt16 (int camera, int category, int paramNo, int paramVal, int paramMax, int base, int multiplier);
  void setFixed16 (int camera, int category, int paramNo, int paramVal, int paramMax, int base, int multiplier);
*/


long int irqcounter = 0;
unsigned long irqcounter2 = 0;

// debounce management
static boolean rotating = false;
// interrupt service routine vars
boolean A_set = false;
boolean B_set = false;

//Strip class
class stripRing
{
  public:
    struct rgba
    {
      byte red;
      byte green;
      byte blue;
      byte alpha;
    };
    Adafruit_NeoPixel* strip;
    uint32_t redcolor = strip->Color(255, 0, 0);
    uint32_t bluecolor = strip->Color(0, 0, 255);
    uint32_t greencolor = strip->Color(0, 255, 0);
    uint32_t whitecolor = strip->Color(255, 255, 255);
    uint32_t menucolor = strip->Color(255, 255, 255);
    int pointPos;
    uint32_t pointColor;
    int phase;
    int maxPos;
    rgba theStrip[24];
    int phaseDir;
    int pPosition;
    int aniType;
    int ringPos;
    bool sleep = false;

    stripRing (Adafruit_NeoPixel* theStrip)
    {
      strip = theStrip;
      pointPos = 0;
      pointColor = menucolor;
      maxPos = 24;
      phase = 8;
      phaseDir = 1;
      aniType = 2;
      ringPos = 0;


    }
    void init()
    {
      strip->begin();
      strip->setBrightness(10);
      // point(0, 24, menucolor);
      for (int i; i < 24; i++)
      {
        theStrip[i].red = 0x15;
        theStrip[i].green = 0xe0;
        theStrip[i].blue = 0xfa;
        theStrip[i].alpha = 255;

      }
      fullStrip();
    }
    void point(int pos, int maximum, uint32_t acolor) {
      // strip->clear();
      strip->setPixelColor(pos % maximum, acolor);
      strip->show();
    }
    void drawPoint()
    {
      // strip->clear();
      //cleanStrip();

      //  theStrip[pointPos % maxPos].red = 255;

      //  theStrip[pointPos % maxPos].green = 255;
      //  theStrip[pointPos % maxPos].blue = 255;
      //  theStrip[pointPos % maxPos].alpha = 255;
      phase = 4;
      aniType = 2;
      pushStrip();
      //   Serial.println(millis());
    }
    void doPhase ()
    {
      switch (aniType)
      {
        case 1:
          {
            if (phase > 1)
            {
              phase --;
            }
            pushStrip();
            break;
          }
        case 2:
          {
            fadeStrip();
            phase --;
            break;
          }
        case 3:
          {
            fillStrip();
            phase --;
            break;
          }
        default:
          {
            break;
          }
      }

    }
    void pushStrip()
    {
      //strip->clear();
      for (int i; i < 24; i++)
      {
        strip->setPixelColor(i, theStrip[i].red / phase, theStrip[i].green / phase, theStrip[i].blue / phase, theStrip[i].alpha / phase);
      }

      strip->show();

    }

    void fadeStrip()
    {

      for (int i; i < 24; i++)
      {
        theStrip[i].red = theStrip[i].red / 2;
        theStrip[i].green = theStrip[i].green / 2;
        theStrip[i].blue = theStrip[i].blue / 2;
        theStrip[i].alpha = theStrip[i].alpha / 1;
      }

      cleanStrip();
      theStrip[pointPos].red = 0x15;

      theStrip[pointPos].green = 0xb0;
      theStrip[pointPos].blue = 0xff;
      theStrip[pointPos].alpha = 255;
      if (phase > 0)
      {
        for (int i; i < 24; i++)
        {
          strip->setPixelColor(i, theStrip[i].red , theStrip[i].green , theStrip[i].blue , theStrip[i].alpha );
        }
        strip->show();
      }
    }

    void fillStrip()
    {
      int aRed = 0x15;
      int aGreen = 0xe0;
      int aBlue = 0xfa;
      int aAlpha = 0xff;

      if ( (ringPos == liftR) || (ringPos == gammaR) || (ringPos == gainR) || (ringPos == offsetR) ) {
        aRed = 0xff;
        aGreen = 0x00;
        aBlue = 0x00;
        aAlpha = 0xff;
      }
      if ( (ringPos == liftG) || (ringPos == gammaG) || (ringPos == gainG) || (ringPos == offsetG) ) {
        aRed = 0x00;
        aGreen = 0xff;
        aBlue = 0x00;
        aAlpha = 0xff;
      }
      if ( (ringPos == liftB) || (ringPos == gammaB) || (ringPos == gainB) || (ringPos == offsetB) ) {
        aRed = 0x00;
        aGreen = 0x00;
        aBlue = 0xff;
        aAlpha = 0xff;
      }
      if ( (ringPos == liftL) || (ringPos == gammaL) || (ringPos == gainL) || (ringPos == offsetL) ) {
        aRed = 0xff;
        aGreen = 0xff;
        aBlue = 0xff;
        aAlpha = 0xff;
      }

      cleanStrip();
      for (int i = 0; i < pointPos; i++)
      {
        theStrip[i].red = aRed / 4;
        theStrip[i].green = aGreen / 4;
        theStrip[i].blue = aBlue / 4;
        theStrip[i].alpha = aAlpha;
      }
      theStrip[pointPos].red = aRed;
      theStrip[pointPos].green = aGreen;
      theStrip[pointPos].blue = aBlue;
      theStrip[pointPos].alpha = aAlpha;
      if (phase > 0)
      {
        for (int i; i < 24; i++)
        {
          strip->setPixelColor(i, theStrip[i].red , theStrip[i].green , theStrip[i].blue , theStrip[i].alpha );
        }
        strip->show();
      }
    }
    void cleanStrip()
    {
      for (int i; i < 24; i++)
      {
        theStrip[i].red = 0;
        theStrip[i].green = 0;
        theStrip[i].blue = 0;
        theStrip[i].alpha = 0;

      }
    }
    void fullStrip()
    {
      for (int i; i < 24; i++)
      {
        theStrip[i].red = 0x15;
        theStrip[i].green = 0xe0;
        theStrip[i].blue = 0xfa;
        theStrip[i].alpha = 255;

      }
    }
    void sleepIt()
    {
      sleep = true;
      for (int i = 0; i < 24; i++)
      {
        strip->setPixelColor(i, 0, 0, 0, 0 );
      }
      strip->show();
    }
    void wakeIt()
    {
      sleep = false;
      for (int i = 0; i < 24; i++)
      {
        strip->setPixelColor(i, theStrip[i].red, theStrip[i].green, theStrip[i].blue, theStrip[i].alpha);
      }

      strip->show();
    }
};

//Display class

class displayScreen
{
  public:


    SSD1306AsciiWire* oled;
    String firstRow;
    String secondRow;
    String thirdRow;
    String fourthRow;
    int editRow;
    bool dirtyState;
    int thirdRowMaxVal;
    int thirdRowCurVal;
    int modal;
    float timeProp;
    unsigned long timeSpan;
    int serialBatch;
    int serialItem;
    bool sleep = false;

    displayScreen ()
    {
      dirtyState = true;
      editRow = 0;
      firstRowFont = Consolas15;
      secondRowFont = shared32;
      thirdRowFont = font5x7;
      thirdRowMaxVal = 0;
      thirdRowCurVal = 0;
      fourthRowFont = font5x7;
      modal = 1;
      sleep = false;



    };
    void setFirstRow(String linia)
    {
      while (linia.length() < 15)
      {
        linia = linia + " ";
      }


      firstRow = linia;
      dirtyState = true;
    };
    void setSecondRow(String linia)
    {

      secondRow = centerMessage(linia, shared32);
      dirtyState = true;
    };
    void setThirdRow(String linia)
    {
      thirdRow = linia;
      dirtyState = true;
    };
    void setFourthRow(String linia)
    {
      fourthRow = centerMessage2(linia, font5x7);
      dirtyState = true;
    }
    void setEditState(int state)
    {
      switch (state) {
        case 0:
          {
            firstRowFont = Consolas15;
            break;
          }
        case 1:
          {
            firstRowFont = Consolas15not;
            break;
          }
        case 2:
          {
            firstRowFont = Consolas15not;
            break;
          }
      }
      editRow = state;
      dirtyState = true;
    }
    void repaintScreen ()
    {
      if (!sleep)
      {
        if (modal == 0)
        {
          String tail;
          if (dirtyState)
          {

            dirtyState = false;
            if (editRow == 0) {
              tail = "~";
            }
            else if (editRow == 1)
            {
              tail = "@";
            }
            else
            {
              tail = "{";
            }
            oled->home();
            oled->setFont(firstRowFont);
            oled->println(firstRow + tail);
            oled->setFont(secondRowFont);
            oled->println(secondRow);
            oled->setFont(thirdRowFont);
            oled->println(pickDivider(float(thirdRowMaxVal), float(thirdRowCurVal)));

            oled->println(fourthRow);
          }
        }
        else if (modal == 1)
        {
          if (dirtyState)
          {

            oled->home();
            oled->setFont(Exo18);
            oled->println("sdi   REMOTE");
            oled->setFont(Consolas15);
            oled->println(centerMessage2(buildNo, Consolas15));
            oled->setFont(Consolas15);
            oled->println(centerMessage2("Serial: B" + String(serialBatch) + "S" + String(serialItem), Consolas15));
            //          Serial.println(String(myEprom.serial.batch) + "S" + String(myEprom.serial.item));
            oled->setFont(thirdRowFont);
            oled->println("      PRESS THE KNOB");

          }
        }
        else if (modal == 2)
        {
          if (dirtyState)
          {
            String temp = fromtime((unsigned long)((float)timeSpan * (float)timeProp));
            if (temp != oldMessage)
            {
              //Serial.println("Pik");
              oled->home();
              oled->setFont(firstRowFont);
              setFirstRow("Sequencer");
              oled->println(firstRow + " ");
              oled->setFont(secondRowFont);
              //        Serial.println("Czas:"+ String((unsigned long)((float)timeSpan*(float)timeProp)));
              //        Serial.println(fromtime((unsigned long)((float)timeSpan*(float)timeProp)));
              setSecondRow(temp);
              oled->println(secondRow );
              oled->setFont(thirdRowFont);
              oled->println(pickDivider2(timeProp));
              setFourthRow(fromtime(timeSpan));
              oled->println(fourthRow);
              //      oled->println(fourthRow);
              oldMessage = temp;
            }
          }
        }
      }
    };
    void sleepIt()
    {
      if (!sleep)
      {
        sleep = true;
        oled->home();
        oled->clear();
      }
    }
  private:
    const uint8_t *  firstRowFont;
    const uint8_t *  secondRowFont;
    const uint8_t *  thirdRowFont;
    const uint8_t *  fourthRowFont;
    String oldMessage = "";

    String fromtime (unsigned long hms)
    {
      String ret = "";
      hms = hms / 1000;
      ret = ":" + fillTo2(hms % 60);
      //     Serial.println(ret);
      hms = hms / 60;
      ret = ":" + fillTo2(hms % 60) + ret;
      hms = hms / 60;
      ret = fillTo2(hms) + ret;
      return ret;

    }
    String fillTo2(int input)
    {
      String ret = String(input);
      if (ret.length() == 1)
      {
        ret = "0" + ret;
      }
      return ret;

    }
    String centerMessage(String message, const uint8_t *  font)
    {
      int msglen = 0;
      int spacerpt = 0;
      int spaceSize = 0;
      oled->setFont(font);
      for (int i = 0; i < message.length(); i++) {
        msglen = msglen + oled->charWidth(message.charAt(i));
      }
      //spaceSize = oled.charWidth(" ");
      //Serial.println(spaceSize);
      spacerpt = (128 - msglen) / 6;
      for (int i = 0; i < spacerpt; i++) {
        message = " " + message + " ";
      }
      return message;
    }

    String centerMessage2(String message, const uint8_t *  font)
    {
      int msglen = 0;
      int spacerpt = 0;
      int spaceSize = 0;
      oled->setFont(font);
      for (int i = 0; i < message.length(); i++) {
        msglen = msglen + oled->charWidth(message.charAt(i));
      }
      spaceSize = oled->charWidth(0x20);
      //      Serial.println(spaceSize);
      spacerpt = (128 - msglen) / (2 * spaceSize);
      for (int i = 0; i < spacerpt; i++) {
        message = " " + message + " ";
      }
      return message;
    }
    String pickDivider(float maxVal, float curVal) {
      //  float maxVal = float(camParams[row][0]);
      //  float curVal = float(camParams[row][1]);
      float diVal = 0;
      if (maxVal > 0) {
        diVal = float(curVal / maxVal);
      }
      int i;
      i = int(diVal * 28.0);
      String retval = "";
      for (int a = 0; a < i; a++) {
        retval = retval + "~";
      }
      while (retval.length() < 30)
      {
        retval = retval + " ";
      }
      return retval;

    }
    String pickDivider2(float diVal) {
      //  float maxVal = float(camParams[row][0]);
      //  float curVal = float(camParams[row][1]);
      int i;
      i = int(diVal * 28.0);
      String retval = "";
      for (int a = 0; a < i; a++) {
        retval = retval + "~";
      }
      while (retval.length() < 30)
      {
        retval = retval + " ";
      }
      return retval;

    }
};


class rotaryEncoder
{
    struct stackStruct
    {
      int minimum;
      int maximum;
      int value;
      int state;
      int nobound;
    };

  public:
    int knobPos;  //encoder knob position
    volatile unsigned int pressCount;  //encoder push button - cycles remaining pressed

    stackStruct myStack[3];
    stackStruct myRecord;
    int stackIndex;


    int signalPin;
    int encoderPinA;
    int encoderPinB;

    cameraSettings* arrCamParams;

    int buttonPressed;
    int buttonServed;

    int dirtyTurn;
    int dirtyClick;
    int dirtyPress;
    unsigned long lastUpdateTime;
    GeneralMessageFunction onPress;
    GeneralMessageFunction onClick;
    GeneralMessageFunction onTurn;

    rotaryEncoder (cameraSettings* tempParams, int pin, int pinA, int pinB)
    {
      //Encoder hardware init
      signalPin = pin;
      encoderPinA = pinA;
      encoderPinB = pinB;
      pinMode(encoderPinA, INPUT);
      pinMode(encoderPinB, INPUT);
      pinMode(signalPin, INPUT);
      digitalWrite(encoderPinA, HIGH);
      digitalWrite(encoderPinB, HIGH);
      digitalWrite(signalPin, HIGH);
      //Encoder var init
      arrCamParams = tempParams;
      pressCount = 0;  //no button pressed
      //Flow vars init
      lastUpdateTime = 0;
      buttonPressed = 0;
      stopProcessing = 0;
      dirtyTurn = 0;
      dirtyPress = 0;
      dirtyClick = 0;
      myRecord.minimum = 0;
      myRecord.maximum = maxFirstRowEntries;
      myRecord.value = 0;
      myRecord.state = 0;
      myRecord.nobound = 1;
      stackIndex = 0;

    }

    int processModal(int modalState)
    {
      if (pressCount < prevPressCount)  //Button pressed is 0 - prevButtonPressed is > 0 - there is onrelease event
      {
        if (prevPressCount > 20)  //button press lasted 20 cycles before release
        {

          prevPressCount = 0;  //prevButtonPressed = 0
          prevPressCount = pressCount;
          if (modalState != 2)

          {
            return 0;
          }
          else
          {
            return 2;
          }

        }

      }

      prevPressCount = pressCount;

      return modalState;
    }
    void processInt ()
    {


      //Processing encoder button
      if (prevPressCount > 1000)  //button was pressed longer than 1000 cycles
      {
        prevPressCount = 0;
        pressCount = 0;

        if (!stopProcessing) {
          stackIndex = 0;
          myRecord = myStack[stackIndex];
          knobPos = myRecord.value;

          /*         myRecord.minimum = 0;
                   myRecord.maximum = maxFirstRowEntries;
                   myRecord.value = 0;
                   myRecord.state = 0;
                   myRecord.nobound = 1;
                   if (stackIndex == 0)
                   {
                     knobPos = 0;
                   }
                   else
                   {
                     knobPos = myStack[0].value;
                   }
                   stackIndex = 0;

                   knobPos = 0;
          */         dirtyPress++;
          dirtyTurn ++;
          //display and change processing loop notification
        }
        stopProcessing = 1;  //Will not fire untill next long press
      }
      //buttonPressed changes from xx to 0 (key is up)

      if (pressCount < prevPressCount)  //Button pressed is 0 - prevButtonPressed is > 0 - there is onrelease event
      {
        if (prevPressCount > 20)  //button press lasted 100 cycles before release
        {
          prevPressCount = 0;  //prevButtonPressed = 0
          if (stopProcessing == 0) {
            //Menu navigation logic
            stopProcessing = 1;
            if (myRecord.state == 0)
            {
              myStack[stackIndex] = myRecord;
              stackIndex ++;

              myRecord.minimum = 0 + arrCamParams[knobPos].reference;
              myRecord.maximum = arrCamParams[knobPos].numValues + arrCamParams[knobPos].reference;
              myRecord.value = arrCamParams[knobPos].curValue + myRecord.minimum;

              myRecord.nobound = arrCamParams[knobPos].rotateValue;
              myRecord.state = 0;
              if (arrCamParams[knobPos].typeValue < 99)
              {
                myRecord.state = 1;
              }
              else
              {
                dirtyTurn ++;
              }
            }
            else
            {
              stackIndex --;
              myRecord = myStack[stackIndex];

            }
            knobPos = myRecord.value;
            dirtyClick++;

          }

        }
        stopProcessing = 0;
      }

      prevPressCount = pressCount;

      //Processing encoder knob

      if (knobPos != myRecord.value)  //Value is different than last one - there was change
      {
        if (knobPos > myRecord.maximum)  //Value is in range
        {
          if (myRecord.nobound == 1)
          {
            knobPos = myRecord.minimum;
          }
          else
          {
            knobPos = myRecord.maximum;
          }
        }
        if (knobPos < myRecord.minimum)
        {
          if (myRecord.nobound == 1 )
          {
            knobPos = myRecord.maximum;
          }
          else
          {
            knobPos = myRecord.minimum;
          }
        }
        myRecord.value = knobPos;
        if (myRecord.state == 1)
        {
          arrCamParams[myStack[stackIndex - 1].value].curValue = myRecord.value - myRecord.minimum;
        }
        dirtyTurn ++;  // display and change processing loop notification
      }

    }

  private:
    int prevPressCount = 0;
    int stopProcessing = 0;

};


class sequencer
{
    struct cameraState
    {
      int aFocus;
      int aAperture;
      int aZoom;
    };
  public:
    unsigned long startTime;
    unsigned long endTime;
    unsigned long deltaTime;
    float timeProp;
    cameraState startState;
    cameraState endState;
    cameraState deltaState;
    int aCamera = 1;
    int processing = 0;
    int previous = 0;

    sequencer ()
    {

    }

    void setStart (int aFocus, int aAperture, int aZoom)
    {
      startState.aFocus = aFocus;
      startState.aAperture = aAperture;
      startState.aZoom = aZoom;
    }
    void setEnd (int aFocus, int aAperture, int aZoom)
    {
      endState.aFocus = aFocus;
      endState.aAperture = aAperture;
      endState.aZoom = aZoom;
    }
    void setTime(int hour, int minute, int second)
    {
      //      Serial.println ("Godz." + String(hour) + "Min." + String(minute) + "Sek." + String (second));
      deltaTime = totime (hour, minute, second);
      //      Serial.println(deltaTime);
    }
    void prepare()
    {
      deltaState.aFocus = endState.aFocus - startState.aFocus;
      deltaState.aAperture = endState.aAperture - startState.aAperture;
      deltaState.aZoom = endState.aZoom - startState.aZoom;
      startTime = millis();
      endTime = startTime + deltaTime;
      processing = 1;
      previous = 0;
    }
    void finnish()
    {
      processing = 0;
    }
    void doInt()
    {
      float zoomProp;
      float focusProp;
      float apertureProp;


      unsigned long curTime;
      curTime = millis();

      if (endTime < curTime)
      {
        processing = 2;
      }
      if (processing == 1)
      {
        timeProp = (float)(curTime - startTime) / (float)deltaTime;
        //        Serial.println (timeProp, 4);
        if (deltaState.aAperture != 0)
        {
          apertureProp = timeProp * deltaState.aAperture;
          setFixed16(aCamera, 0, 3, (startState.aAperture + apertureProp) * 10, 300, 0, 1);
        }
        if (deltaState.aFocus != 0)
        {
          focusProp = timeProp * deltaState.aFocus;
          // void setFixed16 (int camera, int category, int paramNo, int paramVal, int paramMax, int base, int multiplier)
          setFixed16(aCamera, 0, 0, (startState.aFocus + focusProp) * 10, 1000, 0, 1);
        }
        if (deltaState.aZoom != 0)
        {
          zoomProp = timeProp * deltaState.aZoom;
          setFixed16(aCamera, 0, 8, (startState.aZoom + zoomProp) * 10, 1000, 0, 1);
        }
        //Serial.println (deltaState.aFocus);
      }
    }


    unsigned long totime (int hour, int minute, int second)
    {
      return (unsigned long)(((hour * 60) + minute) * 60 + second) * 1000;
    }
    String fromtime (unsigned long hms)
    {
      String ret = "";
      hms = hms / 1000;
      ret = ":" + printf("%02d", (hms % 60));
      hms = hms / 60;
      ret = ":" + printf("%02d", (hms % 60));
      hms = hms / 60;
      ret = ":" + printf("%02d", hms);

    }
};
// Class of rottary button handler - handles onpressed and onclick onrotate events

//**** Rotary encoder setup
enum PinAssignments {
  encoderPinA = 3,   // right
  encoderPinB = 2,   // left
  clearButton = 4    // another two pins
};



displayScreen myScreen;
//rotaryButton myButton(4, 3, 2);

stripRing myRing(&aStrip);

/*
  String menuName;
  int numValues;
  int curValue;
  int typeValue;
  int bitmaskValue;  //hsb - value group lsb - value index
  int baseValue;
  int mulValue;
  int rotateValue;
  int reference;
*/


class epromLib
{
  public:
    int addrValOffset = 100;
    int addrSetOffset = 0;
    const int valLimit = saveSize;
    serialNo serial;

    epromLib()
    {

    }

    void loadSerial()
    {
      //      EEPROM.get(EEPROM.length() - sizeof(serial) - 1, serial);

      int indeks = EEPROM.length();

      serial.batch = EEPROM.read(4080);
      serial.item = EEPROM.read(4081);

      serial.crc = EEPROM.read(4082);

      Serial.println(serial.batch);
    }
    void saveSerial(int aBatch, int aItem)
    {
      serial.batch = aBatch;
      serial.item = aItem;
      serial.crc = serial.batch && serial.item;
      int indeks = EEPROM.length();
      EEPROM.update(4080, serial.batch);
      EEPROM.update(4081, serial.item);
      EEPROM.update(4082, serial.crc);

    }
    void loadMD5()
    {

    }
    void loadSettings()  //Ładujemy 4 zmienne z początku pamięci eeprom
    {




      //104,105,106,107
      for (int i = settingsStart; i <= settingsEnd; i++) {
        camParams[i].curValue = EEPROM.read(addrSetOffset + i - settingsStart);
      }

    }
    void saveSettings()  //Ładujemy 4 zmienne z początku pamięci eeprom
    {
      //104,105,106,107
      for (int i = settingsStart; i <= settingsEnd; i++) {
        EEPROM.update(addrSetOffset + i - settingsStart, camParams[i].curValue);
      }
    }

    void loadVals(int bankNo)
    {
      int addr = 0;
      const int limit = saveSize;
      addr = addr + addrValOffset + bankNo * valLimit;
      for (int i = 0; i < valLimit; i++) {
        if ((i < 91) | (i > 97))
        {
          camParams[i].curValue = EEPROM.read(addr + i);
        }
      }
    }
    void saveVals(int bankNo)
    {
      int addr = 0;
      const int limit = saveSize;
      addr = addr + addrValOffset + bankNo * valLimit;
      for (int i = 0; i < valLimit; i++) {
        EEPROM.update(addr + i, camParams[i].curValue);
      }
    }
    int getVal(int bankNo, int valNo)
    {
      int addr = 0;
      const int limit = saveSize;
      addr = addr + addrValOffset + bankNo * valLimit;
      return  EEPROM.read(addr + valNo);
    }

};

rotaryEncoder myButton(camParams, 4, 3, 2);
epromLib myEprom;
sequencer mySequencer;
unsigned long sleepCounter = 0;
unsigned long sleepTrap = 6000;

void setup() {

  //**** Ustawienie SDI Shield
  sdiCameraControl.begin();

  // Turn on control overrides
  sdiCameraControl.setOverride(true);

  Wire.begin();
  oled.set400kHz();
  oled.begin(&Adafruit128x64, I2C_ADDRESS);



  rotating = false;



  myScreen.oled = &oled;
  myButton.onPress = pressBack;
  myButton.onClick = clickBack;
  myButton.onTurn = turnTop;
  myButton.myRecord.minimum = 0;
  myButton.myRecord.maximum = maxFirstRowEntries;
  myButton.myRecord.value = 0;
  myButton.myRecord.state = 0;
  myButton.myRecord.nobound = 1;
  myButton.stackIndex = 0;

  //Oled setup

  myRing.init();
  myRing.fullStrip();
  myRing.pushStrip();
  myScreen.firstRow = "sdi REMOTE";
  myScreen.repaintScreen();
  //Menu config

  noInterrupts();
  // Timer interrupt:
  Serial.begin(9600);
  Serial.println("Start");
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  interrupts();
  //   myEprom.saveSettings();

  myEprom.loadSettings();
  if (camParams[bootLoading].curValue < 5)
  {
    myEprom.loadVals(camParams[bootLoading].curValue);
    if (camParams[bootUpdate].curValue == 1)
    {
      updateAll();
    }
  }
  #ifdef __FIRST__
    myEprom.saveSerial(11, 205);
  #endif
  myEprom.loadSerial();
  myScreen.serialBatch = myEprom.serial.batch;
  myScreen.serialItem = myEprom.serial.item;
  #ifdef __FIRST__
   Serial.println(myEprom.serial.batch);
  #endif
  myScreen.dirtyState = true;
  myScreen.modal = 1;
  myScreen.repaintScreen();

  sleepCounter = 0;
  setSleep(camParams[sleepDelayId].curValue);



}


void loop() {
  unsigned long mil;

  bool repaint;
  if (lowByte(myEprom.serial.batch && myEprom.serial.item) != myEprom.serial.crc)
  {
    delay(10000);

  }
  repaint = myButton.dirtyTurn | myButton.dirtyPress | myButton.dirtyClick;
  // repaint = true;
  rotating = true;  // reset the debouncer
  if (myButton.dirtyTurn > 0)
  {
    //    myMenuState.setRowState(myButton.knobPos);
    if (myButton.myRecord.state == 0)
    {
      turnTop(myButton.myRecord.value);
      // DebugInfo;
    }
    else
    {
      turnBottom(myButton.myStack[myButton.stackIndex - 1].value, myButton.myRecord.value);
      // DebugInfo;

    }
    myButton.dirtyTurn --;

  }

  if (myButton.dirtyPress > 0)
  {
    myButton.dirtyPress --;
    pressBack();
    repaint = true;

  }

  if (myButton.dirtyClick > 0)
  {
    myButton.dirtyClick --;
    clickBack();
    repaint = true;


    //    myScreen.modal = 0;

  }


  if (irqcounter2 > 50)
  {

    irqcounter2 = 0;
    if (mySequencer.processing == 1)
    {
      mySequencer.doInt();
      //myScreen.setSecondRow( = mySequencer.timeProp;
    }
    if (mySequencer.processing == 2)
    {
      mySequencer.finnish();
      myScreen.modal = 0;
      exitToTop();
      repaint = true;
    }

  }
  if (irqcounter > 200)
  {
    irqcounter = 0;
    myRing.doPhase();
    //Serial.println(millis());
    if (mySequencer.processing == 1)
    {
      myScreen.timeProp = mySequencer.timeProp;
      //      myScreen.setThirdRow(String(mySequencer.timeProp));
      myScreen.dirtyState = true;
      repaint = true;
    }


  }
  //Sleep subroutine
  if (sleepTrap > 0)
  {
    if (sleepCounter > sleepTrap)
    {
      if (!myScreen.sleep)
      {
        myScreen.sleepIt();
        myRing.sleepIt();
        repaint = true;
      }
    }
    else
    {
      if (myScreen.sleep)
      {
        myScreen.sleep = false;
        myRing.wakeIt();
        repaint = true;
      }
    }
  }

  if (repaint)
  {
    myScreen.setEditState(myButton.myRecord.state);
    myScreen.repaintScreen();
  }


}

void turnTop(int encoderPos) {

  myScreen.setFirstRow(camParams[encoderPos].menuName);
  myScreen.setSecondRow(pickMsg(encoderPos, camParams[encoderPos].curValue, camParams[encoderPos].reference));
  myScreen.thirdRowMaxVal = camParams[encoderPos].numValues;
  myScreen.thirdRowCurVal = camParams[encoderPos].curValue;
  myScreen.setFourthRow("  ");
  if (myButton.stackIndex == 0)
  {
    myRing.pointPos = encoderPos % 24;

    myRing.aniType = 2;
    myRing.phase = 8;
    myRing.fadeStrip();
  }
  else
  {
    //myRing.pointPos = (encoderPos - myButton.myRecord.minimum) % 24;
    myRing.pointPos = (float((encoderPos - myButton.myRecord.minimum)) / float(myButton.myRecord.maximum - myButton.myRecord.minimum) * 23) >= 0 ? (float((encoderPos - myButton.myRecord.minimum)) / float(myButton.myRecord.maximum - myButton.myRecord.minimum) * 23) : 0;
    Serial.println (myRing.pointPos);
    myRing.aniType = 3;
    myRing.phase = 8;
    //    myRing.ringPos = topPos;
    myRing.fillStrip();

  }

  // myRing.drawPoint();
  //  DebugInfo();

}


void turnBottom(int topPos, int encoderPos) {
  int correctPos = 0;
  myScreen.setFirstRow(camParams[topPos].menuName);
  myScreen.setSecondRow(pickMsg(topPos, camParams[topPos].curValue, camParams[topPos].reference));
  myScreen.thirdRowMaxVal = camParams[topPos].numValues;
  myScreen.thirdRowCurVal = camParams[topPos].curValue;
  myScreen.setFourthRow(" ");
  myRing.pointPos = (float(camParams[topPos].curValue) / float(camParams[topPos].numValues) * 23) >= 0 ? (float(camParams[topPos].curValue) / float(camParams[topPos].numValues) * 23) : 0;
  myRing.aniType = 3;
  myRing.phase = 8;
  myRing.ringPos = topPos;
  myRing.fillStrip();
  correctPos = encoderPos - camParams[topPos].reference;

  if (correctPos < 0)
  {
    correctPos = 0;
  }
  rollBottom(correctPos, topPos);

  //  myRing.drawPoint();
  //  DebugInfo();

}
String pickMsg(int index, int value, int offset)
{
  if (index == 7)
  {
    return String(isoBase + value * 100) + "K";
  }
  if (offset == 0)
  {
    return String(value);
  }
  else
  {
    return camParams[offset + value].menuName;
  }

}


void rollBottom(unsigned int localencoderPos, int localencoderPosTop)
{

  int maxRoll = camParams[localencoderPosTop].numValues;
  float scaledZoom;
  int valType = 0;

  valType = camParams[localencoderPosTop].typeValue;
  switch (valType) {
    case 0:
      setFixed16(camParams[cameraId].curValue,
                 highByte(camParams[localencoderPosTop].bitmaskValue),
                 lowByte(camParams[localencoderPosTop].bitmaskValue),
                 localencoderPos,
                 maxRoll,
                 camParams[localencoderPosTop].baseValue,
                 camParams[localencoderPosTop].mulValue);
      break;
    case 1:
      setBoolean(camParams[cameraId].curValue,
                 highByte(camParams[localencoderPosTop].bitmaskValue),
                 lowByte(camParams[localencoderPosTop].bitmaskValue),
                 localencoderPos);
      break;
    case 3:
      setInt16(camParams[cameraId].curValue,
               highByte(camParams[localencoderPosTop].bitmaskValue),
               lowByte(camParams[localencoderPosTop].bitmaskValue),
               localencoderPos,
               maxRoll,
               camParams[localencoderPosTop].baseValue,
               camParams[localencoderPosTop].mulValue);
      break;
    case 4:
      setInt8(camParams[cameraId].curValue,
              highByte(camParams[localencoderPosTop].bitmaskValue),
              lowByte(camParams[localencoderPosTop].bitmaskValue),
              localencoderPos);
      break;
    case 6:
      myScreen.setFourthRow("EXECUTING...");
      myScreen.repaintScreen();
      setVoid(camParams[cameraId].curValue,
              highByte(camParams[localencoderPosTop].bitmaskValue),
              lowByte(camParams[localencoderPosTop].bitmaskValue));
      // LightCircle(24,24, 96,96,96);
      myScreen.setFourthRow("EXECUTED");
      exitToTop();
      break;
    case 10:  //Video mode
      // camParams[localencoderPosTop][1] = localencoderPos;
      setVideoMode(camParams[cameraId].curValue,
                   highByte(camParams[localencoderPosTop].bitmaskValue),
                   lowByte(camParams[localencoderPosTop].bitmaskValue),
                   localencoderPos);
      break;
    case 11:  //Gain
      setGain(camParams[cameraId].curValue,
              highByte(camParams[localencoderPosTop].bitmaskValue),
              lowByte(camParams[localencoderPosTop].bitmaskValue),
              localencoderPos);

      break;
    case 12: //Audio Lvl
      // camParams[localencoderPosTop][1] = localencoderPos;
      setAudioLvl(camParams[cameraId].curValue,
                  highByte(camParams[localencoderPosTop].bitmaskValue),
                  lowByte(camParams[localencoderPosTop].bitmaskValue));
      break;
    case 13:  //Lift
      // camParams[localencoderPosTop][1] = localencoderPos;
      setQuadruple(camParams[cameraId].curValue,
                   highByte(camParams[localencoderPosTop].bitmaskValue),
                   lowByte(camParams[localencoderPosTop].bitmaskValue),
                   liftR);

      break;
    case 14:  //Gamma
      // camParams[localencoderPosTop][1] = localencoderPos;
      setQuadruple(camParams[cameraId].curValue,
                   highByte(camParams[localencoderPosTop].bitmaskValue),
                   lowByte(camParams[localencoderPosTop].bitmaskValue),
                   gammaR);

      break;
    case 15:  //Gain
      // camParams[localencoderPosTop][1] = localencoderPos;
      setQuadruple(camParams[cameraId].curValue,
                   highByte(camParams[localencoderPosTop].bitmaskValue),
                   lowByte(camParams[localencoderPosTop].bitmaskValue),
                   gainR);

      break;
    case 16:  // Offset
      // camParams[localencoderPosTop][1] = localencoderPos;
      setQuadruple(camParams[cameraId].curValue,
                   highByte(camParams[localencoderPosTop].bitmaskValue),
                   lowByte(camParams[localencoderPosTop].bitmaskValue),
                   offsetR);

      break;
    case 17:  // Contrast
      // camParams[localencoderPosTop][1] = localencoderPos;
      setDouble(camParams[cameraId].curValue,
                highByte(camParams[localencoderPosTop].bitmaskValue),
                lowByte(camParams[localencoderPosTop].bitmaskValue),
                contrastPiv);

      break;
    case 18:  // HLS
      // camParams[localencoderPosTop][1] = localencoderPos;
      setDouble(camParams[cameraId].curValue,
                highByte(camParams[localencoderPosTop].bitmaskValue),
                lowByte(camParams[localencoderPosTop].bitmaskValue),
                hsHue);

      break;
    case 20:
      for (int i = liftR; i <= hsSat; i++) {
        camParams[i].curValue = cameraDefaults[i];
      }
      setVoid(camParams[46].curValue,
              highByte(camParams[localencoderPosTop].bitmaskValue),
              lowByte(camParams[localencoderPosTop].bitmaskValue));
      //LightCircle(24,24, 96,96,96);
      exitToTop();
      break;
    case 21:
      //      myEprom.saveVals(camParams[localencoderPosTop].curValue - camParams[localencoderPosTop].reference);
      //      exitToTop();

      break;
    case 22:
      //      myEprom.loadVals(camParams[localencoderPosTop].curValue - camParams[localencoderPosTop].reference);
      //      exitToTop();
      break;
    case 23:
      updateAll();

      exitToTop();
      break;
    case 24:
      resetAll();
      break;
    case 33:
      doSequence ();
      //      exitToTop();
      break;
    case 34:
      exitToTop();
      break;
    case 53:
      setSleep(camParams[sleepDelayId].curValue);
      break;
    case 54:
      //      exitToTop();
      myScreen.dirtyState = true;
      myScreen.modal = 1;
      myScreen.repaintScreen();
      break;
    case 55:
      myEprom.saveSettings();
      //    Serial.println("Jest");
      exitToTop();
    default:
      break;
  }

}

void setSleep(int sleepVal)
{
  switch (sleepVal) {
    case 0:
      sleepTrap = 60000;
      break;
    case 1:
      sleepTrap = 120000;
      break;
    case 2:
      sleepTrap = 600000;
      break;
    case 3:
      sleepTrap = 1800000;
      break;
    case 4:
      sleepTrap = 0;
      break;
    default:
      break;
  }
}
void doSequence()
{

  //  Serial.println("Sekwencja");
  int myAddr = camParams[seqModeFrom].curValue;
  //Focus - 0
  //  Serial.println(myAddr);
  mySequencer.setStart(myEprom.getVal(myAddr, 0), myEprom.getVal(myAddr, 2), myEprom.getVal(myAddr, 4));
  //  Serial.println(myEprom.getVal(myAddr, 0));
  myAddr = camParams[seqModeTo].curValue;
  mySequencer.setEnd(myEprom.getVal(myAddr, 0), myEprom.getVal(myAddr, 2), myEprom.getVal(myAddr, 4));

  mySequencer.setTime(camParams[seqModeHours].curValue, camParams[seqModeMinutes].curValue, camParams[seqModeSeconds].curValue);
  mySequencer.aCamera = camParams[cameraId].curValue;
  myScreen.setFourthRow ("SEQUENCE RUNNING");
  myScreen.timeProp = 0;
  myScreen.timeSpan = mySequencer.deltaTime;
  myScreen.modal = 2;

  //  myScreen.dirtyState = 1;

  mySequencer.prepare();
}

void updateAll() {
  myScreen.setFourthRow("UPDATING...");
  myScreen.repaintScreen();
  for (int i = 0; i <= 8; i++) {

    if ((camParams[i].typeValue != 6) & (camParams[i].typeValue != 99)) {
      ///Serial.println(i);
      rollBottom(camParams[i].curValue, i);
      myRing.pointPos = float(i) / 36.0 * 24 - 1;
      myRing.aniType = 3;
      myRing.phase = 8;
      myRing.ringPos = 99;
      myRing.fillStrip();
      // delay(100);
    }
  }

  //24-51
  for (int i = 24; i <= 51; i++) {

    if ((camParams[i].typeValue != 6) & (camParams[i].typeValue != 99)) {
      rollBottom(camParams[i].curValue, i);
      myRing.pointPos = float(i - 24 + 9) / 36.0 * 24 - 1;
      myRing.aniType = 3;
      myRing.phase = 8;
      myRing.ringPos = 99;
      myRing.fillStrip();
      //delay(100);
    }

  }
  rollBottom(camParams[2].curValue, 2);

  myScreen.setFourthRow("SETTINGS UPDATED");

}

void resetAll()
{
  myScreen.setFourthRow("RESETTING...");
  myScreen.repaintScreen();
  for (int i = 0; i < defaultsNumber - 5; i++) {
    camParams[i].curValue = cameraDefaults[i];
  }
  for (int i = 0; i < 5 ; i++) {
    camParams[94 + i].curValue = cameraDefaults[65 + i];
  }
  myScreen.setFourthRow("SETTINGS RELOADED");

  exitToTop();
}
void checkExit (int valType, int posBottom) {
  // Serial.println(String(valType) + " : " + String (posBottom));
  switch (valType) {
    case 21:
      if (posBottom < 5) {
        myScreen.setFourthRow("SAVING...");
        myScreen.repaintScreen();
        myEprom.saveVals(posBottom);
        myScreen.setFourthRow("SAVED");
        myScreen.repaintScreen();
      }

      exitToTop();
      break;
    case 22:
      if (posBottom < 5) {
        myScreen.setFourthRow("LOADING...");
        myScreen.repaintScreen();
        myEprom.loadVals(posBottom);
        myScreen.setFourthRow("LOADED");
        myScreen.repaintScreen();
      }

      exitToTop();
      break;
    default:
      break;
  }
}
void exitToTop()
{
  if (myButton.myRecord.state > 0)
  {
    //    int tmp = myButton.
    //    Serial.println(myButton.myStack[myButton.stackIndex - 1].value);
    myButton.stackIndex = 0;
    myButton.myRecord = myButton.myStack[myButton.stackIndex];
    myButton.knobPos = myButton.myRecord.value;
    turnTop(myButton.myRecord.value);
    //   myScreen.dirtyState = true;

    /*    myButton.dirtyTurn = 1;
        myButton.myRecord.state = 0;*/
    //   myScreen.repaintScreen();
  }
}
void pressBack() {

  Serial.println("tutaj");
  //myScreen.setEditState(0);
  exitToTop();
}

void clickBack() {

  if (myButton.myRecord.state == 0)
  {
    checkExit (camParams[myButton.myStack[myButton.stackIndex].value].typeValue, camParams[myButton.myStack[myButton.stackIndex].value].curValue);
    turnTop(myButton.myRecord.value);
  }
  else
  {
    turnBottom(myButton.myStack[myButton.stackIndex - 1].value, myButton.myRecord.value);
  }
  myScreen.dirtyState = true;

}


void DebugInfo()
{
  // Serial.println("Cur Minimum: " + String(myButton.myRecord.minimum) + " maximum: " + String(myButton.myRecord.maximum) + " value: " + String(myButton.myRecord.value) + " row2: " + String(myButton.curMenuStates.rows[2]) );
}

SIGNAL(TIMER0_COMPA_vect)
{
  if (myScreen.modal == 0)
  {
    //Reading encoder rotation
    if ( digitalRead(myButton.encoderPinA) != A_set ) { // debounce once more
      A_set = !A_set;

      // adjust counter + if A leads B
      if ( A_set && !B_set )
      {
        myButton.knobPos += 1;
        sleepCounter = 0;
      }
      rotating = false;  // no more debouncing until loop() hits again
    }
    if ( digitalRead(myButton.encoderPinB) != B_set ) {
      B_set = !B_set;
      //  adjust counter - 1 if B leads A
      if ( B_set && !A_set ) {
        myButton.knobPos -= 1;
        sleepCounter = 0;
      }
      rotating = false;
    }

  }
  //Reading encoder button
  if (!digitalRead(myButton.signalPin))
  {
    myButton.pressCount++;
    sleepCounter = 0;
  }
  else
  {
    myButton.pressCount = 0;
  }
  if (myScreen.modal == 0)
  {
    myButton.processInt();
  }
  else
  {
    myScreen.modal = myButton.processModal(myScreen.modal);
    if (myScreen.modal == 0)
    {
      exitToTop();
    }

  }

  irqcounter ++;
  irqcounter2 ++;
  sleepCounter ++;
}

#ifndef Meter_h
#define Meter_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Meter border color
#define TFT_GREY 0x5AEB

// Meter class
class MeterWidget {
  public:
    MeterWidget(Adafruit_ILI9341* tft);

    void setZones(uint16_t rs, uint16_t re, uint16_t os, uint16_t oe, uint16_t ys, uint16_t ye, uint16_t gs, uint16_t ge);
    void analogMeter(uint16_t x, uint16_t y, float fullScale, const char* units, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4);
    void analogMeter(uint16_t x, uint16_t y, float startScale, float endScale, const char* units, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4);
    void updateNeedle(float value, uint32_t ms_delay);

  private:
    Adafruit_ILI9341* ntft;
    float ltx;
    uint16_t osx, osy;
    int old_analog;
    int old_digital;
    uint16_t mx;
    uint16_t my;
    float factor;
    float scaleStart;
    char mlabel[9];
    char ms0[5];
    char ms1[5];
    char ms2[5];
    char ms3[5];
    char ms4[5];
    int16_t redStart;
    int16_t redEnd;
    int16_t orangeStart;
    int16_t orangeEnd;
    int16_t yellowStart;
    int16_t yellowEnd;
    int16_t greenStart;
    int16_t greenEnd;
};

#endif

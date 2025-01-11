#include "MeterWidget.h"

MeterWidget::MeterWidget(Adafruit_ILI9341* tft) {
  ntft = tft;
  osx = osy = 0;
  old_analog = -999;
  old_digital = -999;
}

void MeterWidget::setZones(uint16_t rs, uint16_t re, uint16_t os, uint16_t oe, uint16_t ys, uint16_t ye, uint16_t gs, uint16_t ge) {
  redStart = rs;
  redEnd = re;
  orangeStart = os;
  orangeEnd = oe;
  yellowStart = ys;
  yellowEnd = ye;
  greenStart = gs;
  greenEnd = ge;
}

void MeterWidget::analogMeter(uint16_t x, uint16_t y, float fullScale, const char* units, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4) {
  mx = x;
  my = y;
  factor = fullScale / 100.0;
  strcpy(mlabel, units);
  strcpy(ms0, s0);
  strcpy(ms1, s1);
  strcpy(ms2, s2);
  strcpy(ms3, s3);
  strcpy(ms4, s4);

  ntft->fillRect(x, y, 220, 135, TFT_GREY);
  ntft->drawRect(x, y, 220, 135, ILI9341_WHITE);
  
  // Draw scale labels and zones here (example for labels)
  ntft->setTextColor(ILI9341_WHITE);
  ntft->setTextSize(1);
  ntft->setCursor(x + 10, y + 115);
  ntft->print(ms0);
  ntft->setCursor(x + 55, y + 115);
  ntft->print(ms1);
  ntft->setCursor(x + 100, y + 115);
  ntft->print(ms2);
  ntft->setCursor(x + 145, y + 115);
  ntft->print(ms3);
  ntft->setCursor(x + 190, y + 115);
  ntft->print(ms4);
}

void MeterWidget::updateNeedle(float value, uint32_t ms_delay) {
  int angle = map(value, 0, 100, -60, 240);
  float radian = angle * 3.14 / 180;
  int x = mx + 110 + cos(radian) * 100;
  int y = my + 135 + sin(radian) * 100;

  if (osx != 0 && osy != 0) {
    ntft->drawLine(mx + 110, my + 135, osx, osy, TFT_GREY);
  }

  ntft->drawLine(mx + 110, my + 135, x, y, ILI9341_RED);
  osx = x;
  osy = y;

  delay(ms_delay);
}

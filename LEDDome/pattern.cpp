#include "pattern.h"

void setAllPixelColor(const Adafruit_NeoPixel *pixels, uint8_t r, uint8_t g, uint8_t b) {
  int16_t pixelCount = pixels->numPixels();
  for (int16_t i = 0; i < pixelCount; i++) {
    pixels->setPixelColor(i, r, g, b);
  }
}

void setAllPixelColor(const Adafruit_NeoPixel *pixels, uint32_t c) {
  int16_t pixelCount = pixels->numPixels();
  for (int16_t i = 0; i < pixelCount; i++) {
    pixels->setPixelColor(i, c);
  }
}


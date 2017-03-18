#ifndef PATTERN_h
#define PATTERN_h

#include <stdint.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

void showPattern01(const Adafruit_NeoPixel *pixels);
void showPattern02(const Adafruit_NeoPixel *pixels);

void setAllPixelColor(const Adafruit_NeoPixel *pixels, uint8_t r, uint8_t g, uint8_t b);
void setAllPixelColor(const Adafruit_NeoPixel *pixels, uint32_t c);

#endif

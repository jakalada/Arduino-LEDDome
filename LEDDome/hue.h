#ifndef HEU_h
#define HEU_h

#include <stdint.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

uint32_t hue(double v);

#endif // HEU_h

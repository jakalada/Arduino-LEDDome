#include "pattern.h"

#include <stdint.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

static void fadeInOut(const Adafruit_NeoPixel *pixels, const uint8_t red, const uint8_t green, const uint8_t blue) {
  for (int16_t i = 2; i <= 20; i++) {
    uint8_t r = red * (0.05 * i);
    uint8_t g = green * (0.05 * i);
    uint8_t b = blue * (0.05 * i);
    setAllPixelColor(pixels, r, g, b);
    pixels->show();
    delay(30);
  }

  for (int16_t i = 20; i >= 2; i--) {
    uint8_t r = red * (0.05 * i);
    uint8_t g = green * (0.05 * i);
    uint8_t b = blue * (0.05 * i);
    setAllPixelColor(pixels, r, g, b);
    pixels->show();
    delay(30);
  }
}

void showPattern01(const Adafruit_NeoPixel *pixels) {
  pixels->setBrightness(32);
  delay(200);

  pixels->clear();
  pixels->show();
  delay(200);

  // 赤色
  fadeInOut(pixels, 255, 0, 0);

  // 黄色
  fadeInOut(pixels, 127, 127, 0);

  // 緑色
  fadeInOut(pixels, 0, 255, 0);

  // 水色
  fadeInOut(pixels, 0, 127, 127);

  // 青色
  fadeInOut(pixels, 0, 0, 255);

  // 紫色
  fadeInOut(pixels, 127, 0, 127);

  pixels->clear();
  pixels->show();
  delay(200);
}

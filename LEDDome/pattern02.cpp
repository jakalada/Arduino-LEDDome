#include "pattern.h"

#include <stdint.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "hue.h"

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

void showPattern02(const Adafruit_NeoPixel *pixels) {
  pixels->setBrightness(32);
  delay(200);

  pixels->clear();
  pixels->show();
  delay(200);

  pixels->clear();
  pixels->show();
  delay(100);

  int16_t pixelCount = pixels->numPixels();

  // ピクセルごとに色相の並びで色を設定
  for (int16_t i = pixelCount - 1; i >= 0; i--) {
    double colorPhase = (double) i / (double) pixelCount;
    uint32_t color = hue(colorPhase);
    pixels->setPixelColor(i, color);
    pixels->show();
    delay(100);
  }

  // ピクセルごとに消灯
  for (int16_t i = pixelCount - 1; i >= 0; i--) {
    pixels->setPixelColor(i, 0, 0, 0);
    pixels->show();
    delay(100);
  }

  pixels->clear();
  pixels->show();
  delay(200);
}

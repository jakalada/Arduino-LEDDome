#include "pattern.h"

#include <stdint.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "hue.h"

void showPattern02(const Adafruit_NeoPixel *pixels) {
  pixels->clear();
  pixels->show();
  delay(200);

  const int16_t pixelCount = pixels->numPixels();

  int32_t hueColors[pixelCount];
  for (int16_t i = 0; i < pixelCount; i++) {
    double colorPhase = (double) i / (double) pixelCount;
    hueColors[i] = hue(colorPhase);
  }

  // 1ピクセルごとに点灯させる
  // 色相の色を順に設定
  for (int16_t i = pixelCount - 1; i >= 0; i--) {
    pixels->setPixelColor(i, hueColors[i]);
    pixels->show();
    delay(50);
  }

  delay(500);

  // 色相を回転させる
  // 色相の色を1個ずつずらしながら点灯
  for (int16_t shift = 0; shift < pixelCount * 2; shift++) {
    for (int16_t i = 0; i < pixelCount; i++) {
      int16_t hueColorIndex = (i + shift) % pixelCount;
      pixels->setPixelColor(i, hueColors[hueColorIndex]);
    }
    pixels->show();
    delay(50);
  }

  // ピクセルごとに消灯
  for (int16_t i = pixelCount - 1; i >= 0; i--) {
    pixels->setPixelColor(i, 0, 0, 0);
    pixels->show();
    delay(50);
  }

  pixels->clear();
  pixels->show();
  delay(200);
}

#include "hue.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

uint32_t hue(double v) {
  static double initial_phase[3] = {
    // red initial phase
    0,
    // green initial phase
    1.0,
    // blue initial phase
    2.0
  };

  if (v < 0.0) {
    v = 0.0;
  } else if (v > 1.0) {
    v = 1.0;
  }
  v *= 3.0;

  // RGBの値を0.0 - 1.0の範囲で算出
  double rgb[3];
  for (int i = 0; i < 3; i++) {
    double phase = fmod(v + initial_phase[i], 3.0);

    // calc sin wave
    rgb[i] = sin(2.0 * M_PI * phase);

    // combine square wave
    if (phase >= 0.25 && phase <= 1.25) {
      rgb[i] += 2.0;
    } else if (phase >= 1.75 && phase <= 2.75) {
      rgb[i] -= 2.0;
    }

    rgb[i] += 1.0;
    
    if (rgb[i] > 2.0) {
      rgb[i] = 2.0;
    } else if (rgb[i] < 0.0) {
      rgb[i] = 0.0;
    }
    rgb[i] /= 2.0;
  }

  // NeoPixelに渡す型に変換
  uint8_t red = 255 * rgb[0];
  uint8_t green = 255 * rgb[1];
  uint8_t blue = 255 * rgb[2];
  return Adafruit_NeoPixel::Color(red, green, blue);
}

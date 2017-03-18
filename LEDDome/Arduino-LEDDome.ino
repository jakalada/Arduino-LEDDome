#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "hue.h"
#include "pattern.h"

const int neoPixelPin   = 6;
const int neoPixelCount = 100;

const Adafruit_NeoPixel neoPixels = Adafruit_NeoPixel(neoPixelCount, neoPixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  neoPixels.begin();

  delay(1000);
}

void loop() {
  showPattern01(&neoPixels);
  showPattern02(&neoPixels);
}

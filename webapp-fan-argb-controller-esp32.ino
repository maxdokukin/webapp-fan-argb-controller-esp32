#include <Adafruit_NeoPixel.h>

// --- Configuration ---
#define NUM_LEDS 20
#define PIN_1 6
#define PIN_2 7
#define BRIGHTNESS 64
#define DELAY_TIME 1000 // Adjust to count faster or slower

// --- Initialize Adafruit NeoPixel Strips ---
Adafruit_NeoPixel strip1(NUM_LEDS, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_LEDS, PIN_2, NEO_GRB + NEO_KHZ800);

void setup() {
  // Power-up safety delay
  delay(3000);
  
  // Initialize Strip 1 (Pin 6)
  strip1.begin();
  strip1.setBrightness(BRIGHTNESS);
  strip1.clear();
  strip1.show(); // Initialize all pixels to 'off'

  // Initialize Strip 2 (Pin 7)
  strip2.begin();
  strip2.setBrightness(BRIGHTNESS);
  strip2.clear();
  strip2.show(); // Initialize all pixels to 'off'
}

void loop() {
  // --- Count LEDs on PIN 6 ---
  for(int i = 0; i < NUM_LEDS; i++) {
    // Red
    strip1.setPixelColor(i, strip1.Color(255, 0, 0)); 
    strip1.show();
    delay(DELAY_TIME);

    // Turn off before moving to the next
    strip1.setPixelColor(i, 0); 
    strip1.show();
  }

  // --- Count LEDs on PIN 7 ---
  for(int i = 0; i < NUM_LEDS; i++) {
    // Red
    strip2.setPixelColor(i, strip2.Color(255, 0, 0)); 
    strip2.show();
    delay(DELAY_TIME);

    // Turn off before moving to the next
    strip2.setPixelColor(i, 0); 
    strip2.show();
  }
}
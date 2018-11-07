//Saved as Gemma_Light_sensor_Neo-Pixel_opposite
//https://learn.adafruit.com/light-activated-pixel-heart/arduino-code
//NeoPixels turn on when an LDR detects that it's dark

#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 4  // This many NeoPixels...
#define LED_PIN  1  // are connected to this DIGITAL pin #.
#define SENSOR   2  // One leg of a photocell LIGHT sensor is connected to this DIGITAL pin #.
                    // The other leg is connected to ground.

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN);

void setup() {
  strip.begin();
  strip.show();                  // Initialize all pixels to 'off'
  pinMode(SENSOR, INPUT_PULLUP); // Enable pull-up resistor on sensor pin
}

//In the loop below, I've programmed the NeoPixels to turn ON only when it's dark.  If you want them to be OFF when it's dark, 
//you can comment out (//) my lines of code and instead use the original lines of code by uncommenting them out.
void loop() {
  // The photocell or light dependent resistor (LDR) is being used as a digital (binary) sensor, so it must be
  // COMPLETELY dark to turn it on, your finger is not opaque enough!
  if(!digitalRead(SENSOR)) {                 // Sensor exposed to light?
    colorWipe(strip.Color(0, 0, 0), 50);     // Animate off
    //colorWipe(strip.Color(255, 0, 255), 50); // Animate purple
  } else {                                   // else sensor is dark
    colorWipe(strip.Color(0, 255, 255), 50); // Animate Cyan... You can change your colors in this line of code, by selecting
                                             // a different hex code.
    //colorWipe(strip.Color(0, 0, 0), 50);     // Animate off
  }
  delay(2); // Pause 2 ms before repeating
}

// Fill pixels one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


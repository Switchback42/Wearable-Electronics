/*
Saved as Gemma_Light_sensor_neopixel_detect DARKNESS.ino

Connect one leg of a light dependent resistor (LDR) or photocell to pin 2 and the other leg to ground.
NeoPixels will turn on when an LDR detects that it's DARK.

The original code, from Becky Stern, is from https://learn.adafruit.com/light-activated-pixel-heart/arduino-code

Board:  Adafruit Gemma (ATtiny85 8MHZ)
Programmer:  USBtinyISP

or 

Board:  Gemma M0
Programmer:  USBasp

*/

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

/*
In the loop below, I've adapted the code so that the NeoPixels only turn ON only when it's DARK.  If you want them to be OFF when it's dark, 
you'll need to adjust the code (see URL above for original code). Since the light dependent resistor (LDR) is being used as a digital
(binary) sensor, it must be COMPLETELY dark to turn it ON; your finger is not opaque enough!
*/

void loop() {
  
  if(!digitalRead(SENSOR)) {                 // Is the sensor exposed to light?  If so, turn off animation.
    colorWipe(strip.Color(0, 0, 0), 50);     // Animate off
    //colorWipe(strip.Color(255, 0, 255), 50); // Animate purple
  } else {                                   // Else, if the sensor is dark...
    colorWipe(strip.Color(0, 255, 255), 50); // Animate cyan.
    //colorWipe(strip.Color(0, 0, 0), 50);     // Animate off
  }
  delay(2); // Pause 2 milliseconds before repeating
}

/* 
In the following function, the NeoPixels will fill, one after the other, with the color programmed in the loop
above.  To change the color, change the hex code above.  
ex.  colorWipe(strip.Color(0, 255, 0), 50); // would be green
*/

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


/*
Saved as Gemma_Light_sensor_neopixel.ino

Connect one leg of a light dependent resistor or photocell (light sensor) to pin 2 and the other leg to ground.  
NeoPixels will turn on when the LDR detects that it's light out.

The original code, from Becky Stern, is from https://learn.adafruit.com/light-activated-pixel-heart/arduino-code

Board:  Adafruit Gemma (ATtiny85 8MHZ)
Programmer:  USBtinyISP

OR

Board:  Gemma M0
Programmer:  USBasp

*/

#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 8  // How many NeoPixels are you using?
#define LED_PIN  1  // This is the DIGITAL pin #that will connect to the data-in pin of the NeoPixels.
#define SENSOR   2  // The LDR (light sensor) connects to this DIGITAL pin #.

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN); // Leave this line alone.

void setup() {
  strip.begin();
  strip.show();                  // This initializes all pixels to 'off'
  pinMode(SENSOR, INPUT_PULLUP); // This enables a pull-up resistor on the sensor pin.
}

/* 
In the loop below, the LDR is being used as a digital (binary) sensor, so it must be COMPLETELY dark to
turn it off; your finger is not opaque enough.
*/
  
void loop() {

  if(!digitalRead(SENSOR)) {                 // Is the sensor exposed to light?
    colorWipe(strip.Color(255, 0, 255), 50); // Animate purple 
  } else {                                   // Else, if the sensor is dark...
    colorWipe(strip.Color(0, 0, 0), 50);     // Animate off
  }
  delay(2); // Pause 2 milliseconds before repeating
}

/* 
In the following function, the NeoPixels will fill, one after the other, with the color
programmed above.  To change the color, change the hex code.  
ex.  colorWipe(strip.Color(255, 0, 0), 50);  // would be red
*/

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


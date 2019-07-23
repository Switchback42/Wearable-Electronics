/*
Saved as Gemma_buttoncycler.ino

This program is based upon Arduino sample code.

Board:  Adafruit Gemma ATtiny85 (8MHZ)
Programmer:  USBtinyISP

or 

Board:  Gemma M0
Programmer:  USBasp

This is a demonstration on how to use an input device to trigger changes on your NeoPixels.

I am using two pieces of conductive fabric that I'll bridge with a metal charm to create a momentary switch.

When sewing your design, connect one piece of fabric to ground and another to a digital IO pin (2).  Make sure the pieces do not touch. 
When you bridge the gap between the two pieces of fabric using a conductor, a new animation will be triggered.
Note that you need to bridge the gap between the pieces of conductive fabric to start the first animation!
*/

#include <Adafruit_NeoPixel.h>

#define SENSOR_PIN   2    // I'm using conductive fabric as a sensor.

#define PIXEL_PIN    1    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 4     // The total number of NeoPixels

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'... The pixels will be 'off' when you turn the Gemma on.
}

void loop() {
  // Get current button state.
  bool newState = digitalRead(SENSOR_PIN);
  
  // Check if state changed from high to low (button press).
  if (newState == LOW && oldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(SENSOR_PIN);
    if (newState == LOW) {
      showType++;
      if (showType > 9)
        showType=0;
      startShow(showType);
    }
  }

  // Set the last button state to the old state.
  oldState = newState;
}

void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
            break;
//You can customize your colors here.
    case 1: colorWipe(strip.Color(0, 255, 255), 50);  // Aqua  
            break;
    case 2: colorWipe(strip.Color(153, 50, 204), 50);  // dark orchid
            break;
    case 3: colorWipe(strip.Color(30, 144, 255), 50);  // dodger blue
            break;
    case 4: theaterChase(strip.Color(128, 0, 128), 50); // purple
            break;
    case 5: theaterChase(strip.Color(0,  206,  209), 50); // dark turquoise
            break;
    case 6: colorWipe(strip.Color(255,  140, 0), 50); // dark orange
            break;
    case 7: rainbow(20);
            break;
    case 8: rainbowCycle(20);
            break;
    case 9: theaterChaseRainbow(50);
            break;
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 2; q++) {
      for (int i=0; i < strip.numPixels(); i=i+2) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+2) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

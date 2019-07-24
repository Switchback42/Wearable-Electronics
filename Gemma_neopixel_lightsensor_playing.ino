/*
Gemma_neopixel_lightsensor_playing.ino

Board: Adafruit Gemma V2 (ATtiny85 @8MHZ)
Programmer:  USBTinyISP

or 

Board: Gemma M0
Programmer:  USBasp

Workshop by Jill Dawson:
Intro to Programming with Arduino:  An Electrifying Way to Add Color, Light, and Interactivity to Your Creations
*/

#include <Adafruit_NeoPixel.h> // this sketch requires the Adafruit_NeoPixel library

#define NEOPIN 1    // This is the # of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4 // This is the # of NeoPixels in the strand
#define SENSOR   2  // One leg of a photocell LIGHT sensor is connected to this DIGITAL pin #.
                    // The other leg is connected to ground.
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 
 
/*
By changing the hexcodes below, you can change the colors of your NeoPixels.
If you want to add more than four colors, you can do so here.  
Notice there are commas following all but the last hexcode; the last one has a semicolon.
*/
  
uint32_t color1 = 0xffff1a, // yellow
         color2 = 0x33cc33, // green
         color3 = 0x004d4d, // teal
         color4 = 0x000099, // blue
         color5 = 0x1a001a, // dark purple
         color6 = 0x4d194d, // magenta
         color7 = 0xff33ff, // lighter pink
         color8 = 0xff4d4d, // coral
         color9 = 0x990000, // red
         color10 = 0xe68a00; // orange  
              
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN,HIGH); //This turns on the onboard LED.
  pinMode(SENSOR, INPUT_PULLUP);  // Enable pull-up resistor on sensor pin
  pixels.begin();
  pixels.setBrightness(197);  //  What would happen if you changed this value?
}
 
void loop() {
if(!digitalRead(SENSOR)) {                 // Is light detected?  If so, turn off all four pixels.
     pixels.setPixelColor(0, 0);
     pixels.setPixelColor(1, 0);
     pixels.setPixelColor(2, 0);
     pixels.setPixelColor(3, 0);
     pixels.show();
    
} else {     // If it's dark... 
spaceship();      // call the spaceship function.
  
       }
  delay(2); // Pause 2 ms before repeating
}

void spaceship(){
    pixels.setPixelColor(0, color1); 
    pixels.setPixelColor(1, color2); 
    pixels.setPixelColor(2, color3);
    pixels.setPixelColor(3, color4);
    delay(200); 
    pixels.show();
    pixels.setPixelColor(0, color2);
    pixels.setPixelColor(1, color3); 
    pixels.setPixelColor(2, color4);
    pixels.setPixelColor(3, color5);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color3);
    pixels.setPixelColor(1, color4);
    pixels.setPixelColor(2, color5);
    pixels.setPixelColor(3, color6);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color4);
    pixels.setPixelColor(1, color5);
    pixels.setPixelColor(2, color6);
    pixels.setPixelColor(3, color7);
    delay(200); 
    pixels.show();
    pixels.setPixelColor(0, color5);
    pixels.setPixelColor(1, color6);
    pixels.setPixelColor(2, color7);
    pixels.setPixelColor(3, color8);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color6);
    pixels.setPixelColor(1, color7);
    pixels.setPixelColor(2, color8);
    pixels.setPixelColor(3, color9);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color7);
    pixels.setPixelColor(1, color8);
    pixels.setPixelColor(2, color9);
    pixels.setPixelColor(3, color10);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color8);
    pixels.setPixelColor(1, color9);
    pixels.setPixelColor(2, color10);
    pixels.setPixelColor(3, color1);
    delay(200); 
    pixels.show();
    pixels.setPixelColor(0, color9);
    pixels.setPixelColor(1, color10);
    pixels.setPixelColor(2, color1);
    pixels.setPixelColor(3, color2);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color10);
    pixels.setPixelColor(1, color1);
    pixels.setPixelColor(2, color2);
    pixels.setPixelColor(3, color3);
    pixels.show();
    delay(200);            
}

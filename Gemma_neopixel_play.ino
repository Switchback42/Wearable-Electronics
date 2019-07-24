/*
Gemma_neopixel_play.ino

Board:  Adafruit Gemma (ATtiny85 8 Mhz)
Programmer:  USBTinyISP

or

Board:  Gemma M0
Programmer:  USBasp

This code is an adaptation of code found on Electronic Handbag Project website; it's been modified for Gemma.
Find the original sketch at:
https://web.archive.org/web/20170228191434/http://www.electronicfashion.co.uk/workshop_checklists.htm

Please visit https://www.rapidtables.com/convert/color/index.html to find additional hexcodes fo changing colors

Intro to Programming with Arduino:  An Electrifying Way to Add Color, Light, and Interactivity to Your Creations
Workshop by Jill Dawson
____________________________________________________________________________________
*/

/*
The first section of code is used to define global objects and call up additional files and libraries that the program needs to use.
 */
#include <Adafruit_NeoPixel.h> // This sketch needs the Adafruit_NeoPixel library

#define NEOPIN 1    // this is the # of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4 // this is the # of NeoPixels in the strand
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 
 
/*
By changing the hexcodes below, you can change the colors of your NeoPixels.
If you want to add more than four colors, you can do so here.  
Notice there are commas following all but the last hexcode; the last one has a semicolon.
 */
uint32_t color1 = 0xff0000, // red  
         color2 = 0x00ff00, // green
         color3 = 0x0000ff, // blue
         color4 = 0xff00ff; // purple 

/*
The second section of code is used for things that only need to happen once, upon start up.
*/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(0, OUTPUT); //For showing a high pin
  digitalWrite(0, HIGH);
  digitalWrite(LED_BUILTIN,HIGH); //This turns the onboard LED on so you know your Gemma is receiving power.
  pixels.begin();
  pixels.setBrightness(85);  //What would happen if you changed this value?
}

/*
The third section of code will repeat in a loop, in the order it was programmed.
*/
void loop() {
    pixels.setPixelColor(0, color1); //What do you think this code is doing?
    pixels.setPixelColor(1, color2);
    pixels.setPixelColor(2, color3);
    pixels.setPixelColor(3, color4);
    pixels.show();    
    delay(200);                      //What do you think this code is doing?
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);                      //What do you think this code is doing?
    pixels.setPixelColor(0, color2);
    pixels.setPixelColor(1, color3);
    pixels.setPixelColor(2, color4);
    pixels.setPixelColor(3, color1);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
    pixels.setPixelColor(0, color3);
    pixels.setPixelColor(1, color4);
    pixels.setPixelColor(2, color1);
    pixels.setPixelColor(3, color2);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
    pixels.setPixelColor(0, color4);
    pixels.setPixelColor(1, color1);
    pixels.setPixelColor(2, color2);
    pixels.setPixelColor(3, color3);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
}

/*
A fourth section may contain functions, or procedures, which are little chunks of code that may be called in the loop above.
*/
void emptyFunction(){
// This function is not currently doing anything, nor has it been called in the loop.  
}


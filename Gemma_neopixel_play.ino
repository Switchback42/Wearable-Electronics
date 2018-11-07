/*
Gemma_neopixel_play.ino

Workshop by Jill Dawson

This code is an adaptation of code I found on Electronic Handbag Project website. 
I have added my own spin, as well as comments.
You can find the original sketch on the Way Back Machine at:
https://web.archive.org/web/20170228191434/http://www.electronicfashion.co.uk/workshop_checklists.htm

Please visit https://www.rapidtables.com/convert/color/index.html to find additional hexcodes fo changing colors
*/

// Coding e-Textiles:  Spaulding High School Wearable Electronics
#include <Adafruit_NeoPixel.h> // this sketch requires you to download the Adafruit_NeoPixel library, which will give
                               // you access to some useful sample code

#define NEOPIN 1    // this is the # of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4 // this is the # of NeoPixels in the strand
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 
 
//By changing the hexcodes below, you can change the colors of your NeoPixels.
//If you want to add more than four colors, you can do so here.  
//Notice there are commas following all but the last hexcode; the last one has a semicolon.
uint32_t color1 = 0xff0000, // red  
         color2 = 0x00ff00, // green
         color3 = 0x0000ff, // blue
         color4 = 0xff00ff; // purple 
     
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN,HIGH); //This turns the onboard LED on so you know your Gemma is receiving power.
  pixels.begin();
  pixels.setBrightness(85);  //What would happen if you changed this value?
}
 
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

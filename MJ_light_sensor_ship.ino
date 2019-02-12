// Coding e-Textiles:  Spaulding High School Wearable Electronics
#include <Adafruit_NeoPixel.h> // this sketch requires you to download the Adafruit_NeoPixel library, which will give
                               // you access to some useful sample code

#define NEOPIN 1    // this is the # of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4 // this is the # of NeoPixels in the strand
#define SENSOR   2  // One leg of a photocell LIGHT sensor is connected to this DIGITAL pin #.
                    // The other leg is connected to ground.
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 
 
//By changing the hexcodes below, you can change the colors of your NeoPixels.
//If you want to add more than four colors, you can do so here.  
//Notice there are commas following all but the last hexcode; the last one has a semicolon.
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
  digitalWrite(LED_BUILTIN,HIGH); //This turns the onboard LED on so you know your Gemma is receiving power.
  pinMode(SENSOR, INPUT_PULLUP); // Enable pull-up resistor on sensor pin
  pixels.begin();
  pixels.setBrightness(197);  //What would happen if you changed this value?
}
 
void loop() {
if(!digitalRead(SENSOR)) {                 // Is light detected?  If so, turn off pixels.
     pixels.setPixelColor(0, 0);
     pixels.setPixelColor(1, 0);
     pixels.setPixelColor(2, 0);
     pixels.setPixelColor(3, 0);
     pixels.show();
    
     } else {     // If it's dark 
spaceship();      // call spaceship function
  
  }
  delay(2);; // Pause 2 ms before repeating
}

void spaceship(){
    pixels.setPixelColor(0, color1); //What do you think this code is doing?
    pixels.setPixelColor(1, color2); //What do you think this code is doing?
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
    pixels.setPixelColor(0, color1);
    pixels.setPixelColor(1, color2);
    delay(200);
    pixels.show();
    pixels.setPixelColor(0, color10);
    pixels.setPixelColor(1, color1);
    pixels.setPixelColor(2, color2);
    pixels.setPixelColor(3, color3);
    pixels.show();
    delay(200);                      //What do you think this code is doing?
    // pixels.setPixelColor(0, 0);
   // pixels.setPixelColor(1, 0);
    // pixels.setPixelColor(2, 0);
    // pixels.setPixelColor(3, 0);
    // pixels.show();
    // delay(400);                      //What do you think this code is doing?

   //original
   // pixels.setPixelColor(0, color2);
   // pixels.setPixelColor(1, color3);
   // pixels.setPixelColor(2, color4);
   // pixels.setPixelColor(3, color1);
   // pixels.show();
   //delay(200);

    


   

}

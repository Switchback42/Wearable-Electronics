/*
Gemma_neopixel_play_with_CLUES_for_CHALLENGE.ino

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

#define NEOPIN 1     // This is the number of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4  // This is the number of NeoPixels in the strand
#define LED1 2       // What might this line of code be used for?
                 
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 

// You are not limited to three colors.  Add more if desired.  Be sure that the last color code has a semi-colon after it. 
uint32_t color1 = 0xff0000, // red  
         color2 = 0x00ff00, // green
         color3 = 0x0000ff; // blue

/*
The second section of code is used for things that only need to happen once, upon start up.
*/
void setup() {
  pixels.begin();
  pixels.setBrightness(85);  //  What would happen if you changed this value?
  pinMode(LED1, OUTPUT);     //  What might this line do?  
  digitalWrite(LED1, LOW);   //  What might this line do?  
}
 
/*
The third section of code will repeat in a loop, in the order it was programmed.
 */
void loop() {
  flash();         // What is this function doing? See below.                
  neopixel();      // What is this function doing?   
  yourFunction();  // The contents of function haven't been written yet. See below.
}

/*
The fourth section contains functions, or procedures, which are little chunks of code that are called in the loop above.
*/
void flash(){ 
digitalWrite (LED1, HIGH);  
delay (1000);
digitalWrite (LED1, LOW);    
delay (1000);     
}

void neopixel(){
    pixels.setPixelColor(0, color1); // What do you think this line of code is doing?
    pixels.setPixelColor(1, color2);
    pixels.setPixelColor(2, color3);
    pixels.setPixelColor(3, color1);
    pixels.show();
    delay(200);                      // What do you think this line of code is doing?
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);      // What do you think this line of code is doing?
    pixels.show();
    delay(400);                      
    pixels.setPixelColor(0, color2);
    pixels.setPixelColor(1, color3);
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
    pixels.setPixelColor(0, color3);
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

//Create your own function between the curly brackets.
void yourFunction(){
  
}


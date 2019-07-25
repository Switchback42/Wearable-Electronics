/*
Gemma_switch_neopixel.ino

Board:  Adafruit Gemma (ATiny85 8Mhz)
Programmer:  USBtinyISP

or 

Board:  Gemma M0
Programmer:  USBasp

Workshop by Jill Dawson
Intro to Programming with Arduino:  An Electrifying Way to Add Color, Light, and Interactivity to Your Creations
___________________
 */

//In the first section, set variables with colors to use and define objects you'll be using.
#include <Adafruit_NeoPixel.h>


uint32_t color1 = 0x00ff00, //green
         color2 = 0x0000ff, //blue
         color3 = 0xff0000; //red

//attach one side of the swith to pin D1 and the other to 3Vo
int switchpin = 1;

//attach the NeoPixel data lead to pin D0
int neopin = 0;

//There is one NeoPixel controlled on D0:  aka neopin
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, neopin);

//The setup will only run once at the start of the program.
void setup() {
pinMode (switchpin, INPUT);  //Gemma will listen for input on pin 1, which is also the pin of the red onboard LED
digitalWrite(switchpin, LOW); //HIGH pulls the pin to ground through the onboard LED, turning it on
pixels.begin();
pixels.setBrightness(25);

}

// The third section is a loop that will run repeatedly to check the value of the switch.
void loop() {
if(digitalRead(switchpin)==HIGH){
  neoPattern(color1);
  } else {
  neoPattern(color2);  
  }
  delay(100);
}

// The fourth section contains the function or procedure that is run in the loop above.  It will flash a color based upon the switch.
void neoPattern(uint32_t acol){
  pixels.setPixelColor(0, acol);
  pixels.show();
  delay(200);
  pixels.setPixelColor(0,0);
  pixels.show();
  delay(200);
}


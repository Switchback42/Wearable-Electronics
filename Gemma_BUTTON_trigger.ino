/*
Gemma_BUTTON_trigger.ino

Board: Adafruit Gemma (ATiny85 @8MHZ)
Programmer:  USBtinyISP

Board:  Gemma M0
Programmer:  USBasp


This program turns the onboard LED on or off, when pressing a pushbutton attached to pin 2.
A LilyPad led (with resistor) is on Pin D0 (aka 0).

Based upon sample code from http://www.arduino.cc/en/Tutorial/Button
 
 Workshop by Jill Dawson
 Intro to Programming with Arduino:  An Electrifying Way to Add Color, Light, and Interactivity to Your Creations

 */

// constants don't change
const int buttonPin = 2;     // the number of the pushbutton pin
const int LED =  0;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP); //for Gemma, you need to set the button to a pull-up
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);// play with other functions here
    function1(); 
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW); // play with other functions here
    function2();
    yourFunction(); // play with this function below
  }
}

void function1(){ //if the button is NOT pressed
digitalWrite(LED, HIGH); 
delay(1000);
digitalWrite(LED, LOW);
delay(1000);
}

void function2(){ //if the button IS pressed
for(int i=0;i<20;i++){ //run through the following code 20 times
digitalWrite(LED, HIGH); 
delay(100);
digitalWrite(LED, LOW);
delay(100);}
digitalWrite(LED, LOW); 
}

void yourFunction(){
// This function is empty  
}


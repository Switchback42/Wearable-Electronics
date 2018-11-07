/*
Ugly Christmas Sweater Dec18
/*
Created by Jill Dawson
23 October 2018

I'm using a LilyPad Arduino, Lilypad Sensors, Neo-Pixels, and LilyPad LEDs.
Be careful using the serial monitor, because there are two sensors (and a random number generator) in the code. 
 
To get the music to flash with LEDs, I borrowed liberally from an Instructable (which didn't actually compile).
The link is here: https://www.instructables.com/id/Lilypad-Arduino-Christmas-Sweater-with-Blinking-Li/

My Neo-Pixel code came, in part, from Adafruit (and Becky Stern's Light-Activated Pixel Heart tutorial).
The link is here: https://learn.adafruit.com/light-activated-pixel-heart/stitch-circuit

I wrote the code for "Rudolph," the temperature & light sensors, and "Baby, It's Cold Outside".
I figured out that I needed to use an internal pull-up resistor and an analog pin in the code for the push button (LilyPad).
The push button toggles the music on or off when pressed.
I added a random function to select a random song choice.
The temperature sensor controls Rudolph's nose and a small motor. 
A light sensor triggers a NeoPixel animation.
*/

#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 8
#define LED_PIN 11
#define lightSensor A0
int lightValue;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN);

int speakerPin = 7;
int buttonPin = A3; //Sew a Lilypad Button Board to pin A1 or A5.  These pins have an internal pull-up resistor.
                    //Pressing this button will turn music on (if it's off) or off (if it's on).  The LED patterns will play regardless.
int led1 = 5; 
int led2 = 6; //pwm capabilities (if needed)
int led3 = 8;
int led4 = 9;  
int motor = 3;  //the motor is triggered by the temperature sensor.
int led5 = 13;  //Rudolph's nose will turn on with motor, triggered by temperature sensor
int sensorPin = A2; //TEMPERATURE
int sensorValue;

int switchState = LOW;
boolean buttonClear = true; 

long randNumber; // added to generate a random song choice
int songChoice; // generated by random function

int ledPattern = true; 

const int beatLength = 25; //You can change this for individual songs later.

void setup() {
//Serial.begin(9600);  //Uncomment this below to see your random number...initializes the serial port
strip.begin();
strip.show();
pinMode(lightSensor, INPUT);
//Serial.begin(9600);  //Uncomment this line to see light sensor data...initializes the serial port
pinMode(sensorPin, INPUT); //set the temp sensor to input
//Serial.begin(9600); ////Uncomment this line to see temp sensor data ... initializes the serial port
pinMode(motor, OUTPUT);  //makes the motor an output
pinMode(speakerPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);// Lilypad buttons, on pin A5, need to use an internal pullup resistor
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(A1, OUTPUT);   // use with the positive tab of the LIGHT or TEMP SENSOR
digitalWrite(A1, HIGH); //use with the postive tab of the LIGHT or TEMP SENSOR
}

void loop() {
lightValue = analogRead(lightSensor); //LIGHT SENSOR
//Serial.println(lightValue); 
delay(100);
if(lightValue<=20){ //pretty dark
  colorWipe(strip.Color(0,255,0),50);      //Green
  colorWipe(strip.Color(255,0,0),50);      //Red
  colorWipe(strip.Color(0,0,255), 50);     //Blue
}else{
  colorWipe(strip.Color(0,0,0),50);
}
delay(2);

//Rudolph's nose is temperature sensitive
sensorValue = analogRead(sensorPin); //TEMPERATURE SENSOR
//Serial.println(sensorValue);
delay(100);
//When the push button is pressed, the serial monitor appears to stop recording temperature data.  
//The sensor still works.
if(sensorValue >=180) // >=250 turns on when it's hot; <=150 turns on when it's cold; >=180 turns on with warm hand
{
  digitalWrite(led5, HIGH); // turns on Rudolph's nose
  digitalWrite(motor, HIGH); // turns motor on
  digitalWrite(led1, LOW); //turns other LEDs off
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(2000); //delay for 2 seconds
  digitalWrite(led5, LOW);
  digitalWrite(motor, LOW); //turn motor off
  delay(500); //delay for 1/2 second
  digitalWrite(led5, HIGH);
  digitalWrite(motor, HIGH); //turns motor on
  delay(2000); //delay for 2 seconds
  digitalWrite(led5, LOW);
  digitalWrite(motor, LOW); //turn motor off
  delay (500);
  digitalWrite(led5, HIGH);
  digitalWrite(motor,HIGH);
  delay (2000);
  digitalWrite(led5, LOW);
  digitalWrite(motor, LOW); //turn motor off
}
else
{
 digitalWrite(motor, LOW);
 digitalWrite(led5, LOW);
}
/*
1= Baby, It's Cold Outside  
2= We Wish You a Merry Christmas 
3= Deck the Halls
4= Rudolph 
*/

randNumber = random(1,5); //select a random number from 1 to 4
//Serial.println(randNumber); //RANDOM NUMBER 
songChoice = randNumber;
//songChoice = 2; //uncomment if you prefer not to use the random feature
alternateLeds(); //whatever function you have here will run quietly when button not pushed, even if temp sensor is triggered.

//The push button turns off the music, so you won't drive yourself (or your friends) crazy!
updateSwitchState();
if (switchState == HIGH) {
playTune(songChoice); 
    }  
  }

void playTone(int tone, int duration) {
for(long i=0; i<duration * 1000L; i+=tone*2){
digitalWrite(speakerPin, HIGH);
delayMicroseconds(tone);
digitalWrite(speakerPin, LOW);
delayMicroseconds(tone);
  }
}

void playNote(char note, int duration, boolean sharp) {
char names[] = {'bflat', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B' };
int tones[] = { 1073, 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 851, 758, 716, 636, 568, 506};
char names_sharp[] = { 'c', 'd', 'f', 'g', 'a', 'C', 'D', 'F', 'G', 'A' };
int tones_sharp[] = { 1804, 1607, 1351, 1204, 1073, 902, 804, 676, 602, 536 };

if (sharp == false) {
for(int i=0;i<14;i++){
if (names[i] == note) {
playTone(tones[i], duration);
  }
  }
} else {
for(int i=0;i<10;i++){
  if (names_sharp[i] == note) {
  playTone(tones_sharp[i],duration);
    }
    }
  }
}
void updateSwitchState(){ //This is the function that controls the value of the push button
  int val=digitalRead(buttonPin);
  if(val==HIGH){
    buttonClear=true;
  }else{
    if(buttonClear==true){
    if(switchState==LOW){
     switchState=HIGH;
    }else{
      switchState=LOW;
    }
    buttonClear=false;
    }
  }
}
void alternateLeds() {
if (ledPattern == true) {
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
ledPattern = false;
} else {
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
digitalWrite(led4, LOW);
ledPattern = true;
}
}

void parseTune(char notes[], int beatLength, boolean loopSong) {
  boolean play = true;
for(int i=0;notes[i]!='.'&&play==true;i++){
updateSwitchState();
if (switchState == LOW) {
play = false;
} else {
if (notes[i] == ',') {
char len[3];
int count = 0;
while (notes[i+1] >= '0' && notes[i+1] <= '9' && count < 2) {
len[count] = notes[i+1];
count++;
i++;
}
len[count]='0';
int duration = atoi(len);
delay(duration * beatLength);
} else {
alternateLeds();
char note = notes[i];
boolean sharp;
if (notes[i+1] == '#') {
i++;
sharp = true;
} else {
sharp = false;
}
char len[3];
int count = 0;
while (notes[i+1] >= '0' && notes[i+1] <= '9' && count < 2) {
len[count] = notes[i+1];
count++;
i++;
}
len[count] = '0';
int duration = atoi(len);
playNote(note, duration * beatLength, sharp);
}
delay(beatLength / 2);
}
}
if (loopSong == true) {
switchState = LOW;
}
}

void playTune (int tune) {
if (tune == 1) { // Baby, It's Cold Outside...I coded this part!
char notes[] =
"c2a3g1f2C6,c2a3g1f2a4f2f6,c2bflat3a1g2C6,c2bflat3a1g2bflat4g2g6,c2a3g1f2C6,c2a3g1f2a4,C2a4f2g8,8.";
parseTune(notes, beatLength * .5, false);

} else if (tune == 2) { //We Wish You a Merry Christmas
char notes[] =
"d4g4g2a2g2f#2e4c4e4a4a2b2a2g2f#4d4f#4b4b2C2b2a2g4e4d2d2e4a4f#4g8,8.";
parseTune(notes, beatLength *.5 , false);

} else if (tune == 3) { // Deck the Halls
char notes[] =
"D6C2b4a4g4a4b4g4a2b2C2a2b6a2g4f#4g6,2D6C2b4a4g4a4b4g4a2b2C2a2b6a2g4f#4g6,2a6b2C4a4b6C2D4a4b2C#2D4E2F#2G4F#4E4D6,2D6C2b4a4g4a4b4g4E2E2E2E2D6C2b4a4g8,8.";
parseTune(notes, beatLength *.5 , false);

} else if (tune == 4) { // Rudolph...I coded this part!
char notes[] =
"g1a1g2e2C2,a2g5,g1a1g1a1g2C2b6,f1g1f2d2b2,a2g5,g1a1g1a1g2a2,e6,g1a1g2e2C2,a2g5,g1a1g1a1g2c2,b6,f1g1f2d2b2,a2g5,g1a1g1a1g2D2,C6,a2a2C2a2,g2e2g4,f2a2g2f2e6,d2e2g2a2,b2b2b4,C2C2b2a2,g2f2d4,g1a1g2e2c2,a2g5,g1a1g1a1g2C2b6,f1g1f2d2b2,a2g5,g1a1g1a1,g2D2C4.";
parseTune(notes, beatLength, false);
}
}
void colorWipe(uint32_t c, uint8_t wait){
  for(uint16_t i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i,c);
    strip.show();
    delay(wait);
  }
}


//Saved as LilyTiny_LDR_light_sensor

// It works for Lily Tiny.  Use a 2K resistor ...see image on Instructables

//https://www.instructables.com/id/5-Simple-ATtiny85-LDR-Scripts/

int led1 = 0;
int led2 = 1;

int scriptNumber = 1; //here you can select one of the 4 scrips, 1,2,3,4


//if scriptNumber = 1: in the dark, the led on pin 1 is off & the led on pin 0 is on (& vice versa)
//if scriptNumber = 2: LED1 depending on LDR, LED2 is always blinking
//if scriptNumber = 3: fading alternately, speed of fading by LDR
//if scriptNumber = 4: depending on light value, blink alternating or both


int ADC1 = 1; //ADC1 is an LDR on Digital Pin 2 (which is the same as A1)
int call = 0;

long timer;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins 1 & 2 as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  blinkOne(led1, 100);
  delay(500);
  blinkOne(led2, 100);
  call = callibrate();
  timer = millis() + 2000;
}

// the loop function runs over and over again forever
void loop() {

  //script 1: depending on light value, either LED1 or LED2 in turned on
  if ( scriptNumber == 1 ) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    if (  (analogRead ( ADC1 )) > 500 )  //if it's darkish
    {

      digitalWrite(led1, HIGH); //the led on pin 0 is on
      delay(200);
    } else {

      digitalWrite(led2, HIGH); //otherwise,if it's light, the led on pin 1 is on
      delay(200);
    }
    call = callibrate();

  } else if ( scriptNumber == 2 ) { // LED1 depending on LDR, LED2 is glowing

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

    if (  (analogRead ( ADC1 )) > 500 ) //if it's sort of dark to very dark
    {
      digitalWrite(led1, HIGH); //led1 is on
      delay(200);
    } else { //if it's bright
      delay(200);
    }
    call = callibrate();

    if ( timer < millis()) {
      blinkOne(led2, 200);
      timer = millis() + 2000;
    }
  } else if ( scriptNumber == 3 ) {

    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      analogWrite(led1, fadeValue);
      delaySpecial();
    }
 
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(led1, fadeValue);
      delaySpecial();
    }

 
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(led2, fadeValue);
      delaySpecial();
    }
   for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(led2, fadeValue);
     delaySpecial();
    }

    // blinkOne(2, 200);

  } else if ( scriptNumber == 4 ) { //depending on light value, blink alternating or both

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    if (  (analogRead ( ADC1 )) > 500 )
    {
      blinkBoth(200);
      blinkBoth(200);
      blinkBoth(200);
      blinkBoth(200);
      blinkBoth(200);
    } else {
      blinkOne(led1, 1000);
      blinkOne(led2, 1000);
      blinkOne(led1, 1000);
      blinkOne(led2, 1000);
    }


  } else if ( scriptNumber == 5 ) {

    //see separate script with morse code

  }

}

void delaySpecial() {
  delay(1 + abs(analogRead(ADC1) - 300) / 50);
}

void blinkOne ( int whichLed, int howLong )
{
  digitalWrite(whichLed, HIGH);
  delay( howLong);
  digitalWrite(whichLed, LOW);
  delay(howLong);
}

void blinkBoth (   int howLong )
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay( howLong);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(howLong);
}


int callibrate() { // type electret

  int sensor1 = analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  sensor1 += analogRead(ADC1) / 10;
  delay(10);
  return sensor1;

}

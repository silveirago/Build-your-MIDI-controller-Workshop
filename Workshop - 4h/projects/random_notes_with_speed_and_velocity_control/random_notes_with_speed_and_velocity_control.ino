// Use if using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // adds the MIDI library
MIDI_CREATE_DEFAULT_INSTANCE(); 

// Variables are containers of a certain type. INT variables are containers that store an integer number. We use them so the code is more readable.
// Variables can be used values that won't change, like the pin of a potenciometer, or values that will change, like the reading of this potentiometer
int ledPin = 13;
int buttonPin = 2;
int potPin = A0;
int ldrPin = A1;

int delayTime = 100;
int buttonState = HIGH;
int potState = 0;
int ldrState = 0;

int randomNote = 32;

void setup() {

  Serial.begin(31250); // For Serial communication. MIDI baud rate: 31250 - Serial baud rate: 9600
  
  pinMode(ledPin, OUTPUT); //declares a digital pin as an output, for leds, motors, etc
  pinMode(buttonPin, INPUT_PULLUP); //declares a digital pin as an input, for buttons, switches

}

void loop() {
  buttonState = digitalRead(buttonPin); // reads the state of the button and stores in the variable "buttonState"
  potState = analogRead(potPin); // reads the state of the potentiometer 
  potState = map(potState, 0, 1023, 1000, 30); // maps the state of the pot and map it to a usable range
  ldrState = analogRead(ldrPin); // reads the state of the ldr and map it to a usable range
  //Serial.println(ldrState); //prints the value in the serial monitor
  ldrState = map(ldrState, 30, 120, 127, 0); // reads the state of the ldr and map it to a usable range
  
  

  if (buttonState == LOW) { // do somthing if the button is pressed

    randomNote = random(32, 64); // generates a random note between X and Y
    MIDI.sendNoteOn(randomNote, ldrState, 1);  // sends MIDI note on (note, velocity, channel)
    digitalWrite(ledPin, HIGH); // set the pin to high, turns the led on
    delay(potState); // stops everything by X millisencods (uses the potentiometer)
    MIDI.sendNoteOn(randomNote, 0, 1); // sends MIDI note on (note, velocity, channel)
    digitalWrite(ledPin, LOW); // set the pin to low, turns the led off
    delay(potState); // stops everything by X millisencods (uses the potentiometer)
  }

}


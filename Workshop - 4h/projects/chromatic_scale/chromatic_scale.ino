// Use if using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // adds the MIDI library
MIDI_CREATE_DEFAULT_INSTANCE();

// Variables are containers of a certain type. INT variables are containers that store an integer number. We use them so the code is more readable.
// Variables can be used values that won't change, like the pin of a potenciometer, or values that will change, like the reading of this potentiometer
int ledPin = 13;
int delayTime = 40;

void setup() { // happens once when the Arduino starts
  
  Serial.begin(31250); // For Serial communication. MIDI baud rate: 31250 - Serial baud rate: 9600
  pinMode(ledPin, OUTPUT); //declares a digital pin as an output, for leds, motors, etc

}

void loop() { // loops forever
  
  for (int i = 24; i < 90; i++) { 
    // creates a loop that will occur X times (48), 
    // where "i" will be incremented by 1 every loop (i++) and it starts with 36
    
    MIDI.sendNoteOn(i, 127, 1);  // sends MIDI note on (note, velocity, channel)
    digitalWrite(ledPin, HIGH); // set the pin to high, turns the led on
    delay(delayTime); // stops everything by X millisencods
    MIDI.sendNoteOn(i, 0, 1);  // Channel 0, middle C, normal velocity
    digitalWrite(ledPin, LOW); // set the pin to low, turns the led off
    delay(delayTime); // stops everything by X millisencods
  }

}


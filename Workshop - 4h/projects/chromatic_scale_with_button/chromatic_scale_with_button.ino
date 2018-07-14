// Use if using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // adds the MIDI library
MIDI_CREATE_DEFAULT_INSTANCE();

// Variables are containers of a certain type. INT variables are containers that store an integer number. We use them so the code is more readable.
// Variables can be used values that won't change, like the pin of a potenciometer, or values that will change, like the reading of this potentiometer
int ledPin = 13;
int buttonPin = 2;
int delayTime = 100;
int buttonState = HIGH;

void setup() { // happens once when the Arduino starts

  Serial.begin(31250); // For Serial communication. MIDI baud rate: 31250 - Serial baud rate: 9600
  pinMode(ledPin, OUTPUT); //dealcres a digital pin as an output, for leds, motors, etc
  pinMode(buttonPin, INPUT_PULLUP); //declares a digital pin as an input, for buttons, switches

}

void loop() { // loops forever
  buttonState = digitalRead(buttonPin); // reads the state of the button and stores in the variable "buttonState"

  if (buttonState == LOW) { // do somthing if the button is pressed
    for (int i = 36; i < 48; i++) {
      // creates a loop that will occur X times (48),
      // where "i" will be incremented by 1 every loop (i++) and it starts with 36

      MIDI.sendNoteOn(i, 127, 1);  // Channel 0, middle C, normal velocity
      digitalWrite(ledPin, HIGH); // set the pin to high, turns the led on

      delay(delayTime); // stops everything by X millisencods
      MIDI.sendNoteOn(i, 0, 1);  // Channel 0, middle C, normal velocity
      digitalWrite(ledPin, LOW);

      delay(delayTime); // stops everything by X millisencods
    }
  }

}


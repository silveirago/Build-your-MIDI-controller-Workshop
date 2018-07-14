#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();


int button = 2;
int led = 13;

int ledState = HIGH;
int buttonState;
int buttonPState = HIGH;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, ledState);
  Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(button);

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (buttonState != buttonPState) {
      lastDebounceTime = millis();

      if (buttonState == LOW) {

        //Serial.println("button on");
        MIDI.sendNoteOn(36, 127, 1);
      }
      else {
        //Serial.println("button off");
        MIDI.sendNoteOn(36, 0, 1);
      }
      buttonPState = buttonState;
    }
  }



  digitalWrite(led, ledState);

}

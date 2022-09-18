#include <MIDI.h>

// This is needed for the ATMEGA4809. Most boards will probably need to use `Serial` instead of `Serial1` (or CREATE_DEFAULT_INSTANCE()).
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

// Digital pins used for switches (may not be in order since the wiring can be done in different ways).
const uint8_t buttonUnknown = -1;
const uint8_t buttonAPin = 2;
const uint8_t buttonBPin = 4;
const uint8_t buttonCPin = 3;
const uint8_t buttonDPin = 5;
const uint8_t buttonEPin = 6;
const uint8_t buttonFPin = 7;
const uint8_t buttonGPin = 8;
const uint8_t buttonHPin = 9;

// Digital pins used for LEDs.
const uint8_t ledAPin = 11; // D11
const uint8_t ledBPin = 12; // D12
const uint8_t ledCPin = 19; // A5
const uint8_t ledDPin = 15; // A1
const uint8_t ledEPin = 18; // A4
const uint8_t ledFPin = 16; // A2
const uint8_t ledGPin = 13; // D13
const uint8_t ledHPin = 17; // A3

uint8_t lastActiveButton = buttonUnknown;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100;

void setup() {

  MIDI.begin();

  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  pinMode(buttonCPin, INPUT_PULLUP);
  pinMode(buttonDPin, INPUT_PULLUP);
  pinMode(buttonEPin, INPUT_PULLUP);
  pinMode(buttonFPin, INPUT_PULLUP);
  pinMode(buttonGPin, INPUT_PULLUP);
  pinMode(buttonHPin, INPUT_PULLUP);

  pinMode(ledAPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(ledCPin, OUTPUT);
  pinMode(ledDPin, OUTPUT);
  pinMode(ledEPin, OUTPUT);
  pinMode(ledFPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledHPin, OUTPUT);
}

void loop() {

  if (digitalRead(buttonAPin) == LOW) {
    handleButtonPress(buttonAPin);
    return;
  }
  if (digitalRead(buttonBPin) == LOW) {
    handleButtonPress(buttonBPin);
    return;
  }
  if (digitalRead(buttonCPin) == LOW) {
    handleButtonPress(buttonCPin);
    return;
  }
  if (digitalRead(buttonDPin) == LOW) {
    handleButtonPress(buttonDPin);
    return;
  }
  if (digitalRead(buttonEPin) == LOW) {
    handleButtonPress(buttonEPin);
    return;
  }
  if (digitalRead(buttonFPin) == LOW) {
    handleButtonPress(buttonFPin);
    return;
  }
  if (digitalRead(buttonGPin) == LOW) {
    handleButtonPress(buttonGPin);
    return;
  }
  if (digitalRead(buttonHPin) == LOW) {
    handleButtonPress(buttonHPin);
    return;
  }

  lastActiveButton = buttonUnknown;
}

void handleButtonPress(uint8_t button) {

  if (button == lastActiveButton) {
    // this debounce stuff actually stops the button being pressed too frequently, not with too
    // short duration. It also has a side effect of stopping the signal multiple being sent while
    // the button is depressed. This is because the debounce keeps getting reset while it's pressed
    // so it never exceeds debouceDelay.
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // see MIDI IN section of https://downloads.neuraldsp.com/file/quad-cortex/Quad%20Cortex%20User%20Manual%201_0_0.pdf
    // to see what CC messages the QC will accept.

    switch (button) {
      case buttonAPin:
        MIDI.sendControlChange(35, 0, 1);
        break;
      case buttonBPin:
        MIDI.sendControlChange(36, 0, 1);
        break;
      case buttonCPin:
        MIDI.sendControlChange(37, 0, 1);
        break;
      case buttonDPin:
        MIDI.sendControlChange(38, 0, 1);
        break;
      case buttonEPin:
        MIDI.sendControlChange(39, 0, 1);
        break;
      case buttonFPin:
        MIDI.sendControlChange(40, 0, 1);
        break;
      case buttonGPin:
        MIDI.sendControlChange(41, 0, 1);
        break;
      case buttonHPin:
        MIDI.sendControlChange(42, 0, 1);
        break;
    }
    enableLED(button);
  }

  lastActiveButton = button;
}

void enableLED(uint8_t button) {

    // reset all LEDs
    digitalWrite(ledAPin, LOW);
    digitalWrite(ledBPin, LOW);
    digitalWrite(ledCPin, LOW);
    digitalWrite(ledDPin, LOW);
    digitalWrite(ledEPin, LOW);
    digitalWrite(ledFPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledHPin, LOW);


    switch (button) {
      case buttonAPin:
        digitalWrite(ledAPin, HIGH);
        break;
      case buttonBPin:
        digitalWrite(ledBPin, HIGH);
        break;
      case buttonCPin:
        digitalWrite(ledCPin, HIGH);
        break;
      case buttonDPin:
        digitalWrite(ledDPin, HIGH);
        break;
      case buttonEPin:
        digitalWrite(ledEPin, HIGH);
        break;
      case buttonFPin:
        digitalWrite(ledFPin, HIGH);
        break;
      case buttonGPin:
        digitalWrite(ledGPin, HIGH);
        break;
      case buttonHPin:
        digitalWrite(ledHPin, HIGH);
        break;
    }
}
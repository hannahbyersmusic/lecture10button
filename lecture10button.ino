#include "BetterButton.h"

int button1Pin = 32;
int button2Pin = 31;
int button3Pin = 30;
int button4Pin = 29;

BetterButton button1(button1Pin, 0);
BetterButton button2(button2Pin, 1);
BetterButton button3(button3Pin, 2);
BetterButton button4(button4Pin, 3);

void setup() {
  Serial.begin(9600);
  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);
  button3.pressHandler(onPress);
  button3.releaseHandler(onRelease);
  button4.pressHandler(onPress);
  button4.releaseHandler(onRelease);
  Serial.println("test");
}

void loop() {
  button1.process();
  button2.process();
  button3.process();
  button4.process();
}

void onPress(int val) {
  Serial.print(val);
  Serial.println(" on");
  if (val == 0) {
    usbMIDI.sendNoteOn(60, 127, 1);
  }
    if (val == 1) {
    usbMIDI.sendNoteOn(61, 127, 1);
  }
    if (val == 2) {
    usbMIDI.sendNoteOn(62, 127, 1);
  }
    if (val == 3) {
    usbMIDI.sendNoteOn(63, 127, 1);
  }
}

void onRelease(int val) {
  Serial.print(val);
  Serial.println(" off");
    if (val == 0) {
    usbMIDI.sendNoteOff(60, 127, 1);
  }
    if (val == 1) {
    usbMIDI.sendNoteOff(61, 127, 1);
  }
    if (val == 2) {
    usbMIDI.sendNoteOff(62, 127, 1);
  }
    if (val == 3) {
    usbMIDI.sendNoteOff(63, 127, 1);
  }
}

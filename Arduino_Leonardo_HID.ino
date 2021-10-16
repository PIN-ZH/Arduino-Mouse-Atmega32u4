#include "Mouse.h"

void setup() {
  //begin the mouse program
  Mouse.begin();
}

void loop() {
  Mouse.press(MOUSE_LEFT); //press the left mouse button
  delay(500); //press button for half a second
  Mouse.release(MOUSE_LEFT); //release left the button
  delay(2500); //wait 2.5 seconds
}

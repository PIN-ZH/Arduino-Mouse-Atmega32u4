#include <Mouse.h>

//Pin numbers
const int buttonPin = 9;   //pushbutton pin
const int ledPin = 10;    //LED pin

//Initial states
int ledState = LOW;           //current state of the LED pin
int buttonState;              //current reading from the pushbutton pin
int lastButtonState = LOW;    //previous reading from the pushbutton pin

//Debounce times in miliseconds
unsigned long lastDebounceTime = 0;  //the last time the output pin was toggled
unsigned long debounceDelay = 50;    //the debounce time

unsigned int counter = 0;
unsigned int no0fPixelsToMove = 50;  //how far to move in each direction
char moveDirection = 'R';            //first move right


void setup() 
{
 pinMode(buttonPin,INPUT);
 pinMode(ledPin,OUTPUT);

 //set initial LED state
 digitalWrite(ledPin,ledState);

 Mouse.begin();
}
void loop() 
{
  //read the state of the switch
  int reading = digitalRead(buttonPin);

  //If the switch changed,reset the debouncing timer
  if (reading !=lastButtonState)
  {
    lastDebounceTime = millis();
  }  
  //If change for longer than the debounce delay,chang the current state
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading !=buttonState)
    {
      buttonState = reading;
      if (buttonState == LOW)
      {
        ledState = !ledState;
      }
    }
  }
  //Only move the mouse when the LED is on
  if (ledState == HIGH)
  {
    counter++;

    //jiggle the mouse right-left
    switch(moveDirection)
    {
      case('R'):
        Mouse.move(1,0,0);  //move right
        break;
      case('L'):
        Mouse.move(1,0,0);  //move right
        break;  
    }

    if (counter > no0fPixelsToMove)
    {
      counter =  0;
      if (moveDirection ==  'L')
        moveDirection = 'R';
      else
        moveDirection = 'L';  
    }
    delay(20);  //delay of 20ms result in a smooth motion
  }
  //set the LED
  digitalWrite(ledPin, ledState);

  // save the switch button state
  lastButtonState = reading; 
}

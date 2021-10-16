#include <Mouse.h> // Special Library
/*
 *  Micro Mouse Wiggler v1
 *  An Arduino (Pro Micro) Hardware Mouse Emulator
 *  OS platform: Windows 10 (x64) 
 *  Arduino IDE: 1.8.13
 *  Project by T.K.Hareendran / 01.2021
 *  Thanks to https://github.com/nshadov
 */
 
int move_interval = 3;
int loop_interval = 15000; // Reiteration time interval
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0)); // See Addendum
  Mouse.begin();
}
void loop()
{
  int distance = random(10, 800);
  int x = random(3) - 1;
  int y = random(3) - 1;
  for (int i = 0; i < distance; i++) {
    Mouse.move(x, y, 0);
    delay(move_interval);
  }
  delay(loop_interval);
}

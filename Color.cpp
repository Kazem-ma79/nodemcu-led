#include "Color.h"

Color::Color(int redPIN, int greenPIN, int bluePIN){
    _redPIN = redPIN;
    _greenPIN = greenPIN;
    _bluePIN = bluePIN;
    pinMode(_redPIN, OUTPUT);
    pinMode(_greenPIN, OUTPUT);
    pinMode(_bluePIN, OUTPUT);
}

void Color::red(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 0);
}

void Color::green(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 0);
}

void Color::blue(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 255);
}

void Color::full(){
  analogWrite(_redPIN, 1023);
  analogWrite(_greenPIN, 1023);
  analogWrite(_bluePIN, 1023);
}

void Color::orange(){
  analogWrite(_redPIN, 237);
  analogWrite(_greenPIN, 109);
  analogWrite(_bluePIN, 0);
}

void Color::lightgreen(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 107);
  analogWrite(_bluePIN, 0);
}

void Color::lightblue(){
  analogWrite(_redPIN, 50);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 107);
}

void Color::lightorange(){
  analogWrite(_redPIN, 150);
  analogWrite(_greenPIN, 109);
  analogWrite(_bluePIN, 0);
}

void Color::lightcyan(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 155);
  analogWrite(_bluePIN, 255);
}

void Color::lightmagenta(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 150);
}

void Color::yellow(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 215);
  analogWrite(_bluePIN, 0);
}

void Color::darkmagenta(){
  analogWrite(_redPIN, 150);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 150);
}

void Color::indigo(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 46);
  analogWrite(_bluePIN, 90);
}

void Color::magenta(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 255);
}

void Color::pink(){
  analogWrite(_redPIN, 158);
  analogWrite(_greenPIN, 4);
  analogWrite(_bluePIN, 79);
}

void Color::cyan(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 255);
}

void Color::white(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 255);
}

void Color::Custom(int RED, int GREEN, int BLUE) {
  analogWrite(_redPIN, RED);
  analogWrite(_greenPIN, GREEN);
  analogWrite(_bluePIN, BLUE);
}

void Color::off(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 0);
}

void Color::rainbow(){
  int FADESPEED = 10;

  for (int r = 0; r < 256; r++) {
   analogWrite(_redPIN, r);
   delay(FADESPEED);
 }
 // fade from violet to red
 for (int b = 255; b > 0; b--) {
   analogWrite(_bluePIN, b);
   delay(FADESPEED);
 }
 // fade from red to yellow
 for (int g = 0; g < 256; g++) {
   analogWrite(_greenPIN, g);
   delay(FADESPEED);
 }
 // fade from yellow to green
 for (int r = 255; r > 0; r--) {
   analogWrite(_redPIN, r);
   delay(FADESPEED);
 }
 // fade from green to teal
 for (int b = 0; b < 256; b++) {
   analogWrite(_bluePIN, b);
   delay(FADESPEED);
 }
 // fade from teal to blue
 for (int g = 255; g > 0; g--) {
   analogWrite(_greenPIN, g);
   delay(FADESPEED);
 }

}

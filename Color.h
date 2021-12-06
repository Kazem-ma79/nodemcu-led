/*
Joe Mulhern 2017
PWM colors for strips. Make with RGB LEDs
*/
#ifndef Color_h
#define Color_h

#include "Arduino.h"

class Color {
  public:
    Color(int redPIN, int greenPIN, int bluePIN);
    void red();
    void green();
    void blue();

    void orange();
    void lightgreen();
    void lightblue();
    void lightorange();
    void darkmagenta();
    void lightmagenta();
    void lightcyan();
    void yellow();
    void indigo();
    void cyan();
    void magenta();
    void white();
    void off();
    void pink();
    void rainbow();
	  void Custom(int red, int green, int blue);
    void full();
  private:
    int _redPIN, _greenPIN, _bluePIN;

};

#endif

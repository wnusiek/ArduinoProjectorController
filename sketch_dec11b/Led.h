#ifndef MY_LED_H
#define MY_LED_H

#include <Arduino.h>

class Led {

private:
  String color;
  int pin;
  boolean state;

public:
  Led();
  Led(String color, int pin);
//  boolean getState();  
  void setState(boolean state);
  void init();
  void turnOn();
  void turnOff();

};

#endif


#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>
#include "Led.h"

class Button {

private:
  String name;
  int pin;
  String projectorCommand;
  Led led;

public:
  Button(String name, int pin, String projectorCommand, Led led);
  boolean isPressed();
  void sendCommand();
  Led getLed();
  String getProjectorCommand();
};

#endif


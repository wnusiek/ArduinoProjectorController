#include "Button.h"

Button::Button(String name, int pin, String projectorCommand, Led led) {
  this->name = name;
  this->pin = pin;
  this->projectorCommand = projectorCommand;
  this->led = led;
  pinMode(pin, INPUT_PULLUP);
}

boolean Button::isPressed() {
  return digitalRead(this->pin) == LOW;
}  
void Button::sendCommand(){
  Serial.println(this->projectorCommand);
  delay(300);
}
Led Button::getLed(){
  return led;
}








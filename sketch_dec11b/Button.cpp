#include "Button.h"

Button::Button(String name, int pin, String projectorCommand, Led led) {
  this->name = name;
  this->pin = pin;
  this->projectorCommand = projectorCommand;
  this->led = led;
  pinMode(pin, INPUT_PULLUP);
}

void Button::checkIfButtonPressed() {
  if (digitalRead(this->pin) == LOW) {
    this->led.turnOn();
    Serial.println(this->projectorCommand);
    delay(300);
  } 
  else {
    digitalWrite(this->pin, LOW);
    delay(10);
  }
}





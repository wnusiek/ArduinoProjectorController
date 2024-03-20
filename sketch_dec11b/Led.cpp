#include "Led.h"

Led::Led(){
}

Led::Led(String color, int pin){
  this->color = color;
  this->pin = pin;
  this->state = false;
  init();
}

//boolean Led::getState(){
//  return state;
//} 

void Led::setState(boolean state){
  this->state = state;
}

void Led::init(){
  pinMode(this->pin, OUTPUT);
  turnOff();
}
void Led::turnOn(){
  digitalWrite(this->pin, HIGH);
  setState(true);
}
void Led::turnOff(){
  digitalWrite(this->pin, LOW);
  setState(false);
}



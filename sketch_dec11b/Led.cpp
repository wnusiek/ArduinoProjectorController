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
  off();
}
void Led::on(){
  digitalWrite(this->pin, HIGH);
  setState(true);
}
void Led::off(){
  digitalWrite(this->pin, LOW);
  setState(false);
}



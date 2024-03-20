#include "Led.h"
#include "Button.h"

void setup() {
  Serial.begin(9600);
}

boolean isOn = false;

Led powerLed("zielona", 8);
Led computer1Led("czerwona", 9);
Led computer2Led("żółta", 10);
Led hdmiLed("niebieska", 11);
Led videoLed("biała", 12);

Led leds[] = {
  powerLed, computer1Led, computer1Led, computer2Led, hdmiLed, videoLed};
Led activeSourceLed;

String getActiveSource(){
  Serial.println("SOURCE?\r\n");
  delay(2000);
  Serial.println(Serial.readString().substring(7,8));
  return Serial.readString();
}

void warmup(){
    int del = 80;
    for (int j = 0; j < 70; j++){
    for (int i = 0; i < sizeof(leds)/sizeof(leds[0]); i++){
      leds[i].on();
      delay(del);
      leds[i].off();
    }
    for (int i = sizeof(leds)/sizeof(leds[0])-1; i--;){
      leds[i].on();
      delay(del);
      leds[i].off();
    }
     del--;
    }   
}
Button powerOnButton("On", 3, "PWR ON\r\n", powerLed);
Button powerOffButton("Off", 3, "PWR OFF\r\n", powerLed);
Button computer1Button("Computer 1 D-SUB VGA", 4, "SOURCE 11\r\n", computer1Led);
Button computer2Button("Computer 2 D-SUB VGA", 5, "SOURCE 21\r\n", computer2Led);
Button hdmiButton("HDMI", 6, "SOURCE 30\r\n", hdmiLed);
Button videoButton("Video", 7, "SOURCE 41\r\n", videoLed);

Button buttons[] = {
  computer1Button, computer2Button, hdmiButton, videoButton  };

Led findActiveSourceLed(){
  for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++){
    if (buttons[i].getProjectorCommand().substring(7,8) == getActiveSource().substring(7,8)){
      return buttons[i].getLed();
    }
  }
}

void loop() {

  if (powerOnButton.isPressed() && !isOn){
    isOn = true;
    powerOnButton.sendCommand();
//    warmup();
    powerLed.on();
    activeSourceLed = findActiveSourceLed();
    activeSourceLed.on();

  } 
  if (powerOffButton.isPressed() && isOn){
    isOn = false;
    powerLed.off();
    activeSourceLed.off();
    powerOffButton.sendCommand();
  }

  if (isOn){
    for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++) {
      if (buttons[i].isPressed()){
        buttons[i].sendCommand();
        activeSourceLed.off();
        activeSourceLed = buttons[i].getLed();
        activeSourceLed.on();
      }
    }
  }

}




#include "Led.h"
#include "Button.h"

void setup() {
  Serial.begin(9600);

}

  boolean isOn = true;

  String returnPowerCommand() {
    String command = "";
    if (isOn == true) {
      command = "PWR OFF\r\n";
      isOn = false;
    } 
    else {
      command = "PWR ON\r\n";
      isOn = true;
    }
    return command;
  };


void loop() {
  Led powerLed("zielona", 8);
  Led computer1Led("czerwona", 9);
  Led computer2Led("żółta", 10);
  Led hdmiLed("niebieska", 11);
  Led videoLed("biała", 12);
  
  Button powerButton("Power", 3, returnPowerCommand(), powerLed);
  Button computer1Button("Computer 1 D-SUB VGA", 4, "SOURCE 11\r\n", computer1Led);
  Button computer2Button("Computer 2 D-SUB VGA", 5, "SOURCE 21\r\n", computer2Led);
  Button hdmiButton("HDMI", 6, "SOURCE 30\r\n", hdmiLed);
  Button videoButton("Video", 7, "SOURCE 41\r\n", videoLed);
  
Button buttons[] = {powerButton, computer1Button, computer2Button, hdmiButton, videoButton};
  for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++) {
    buttons[i].checkIfButtonPressed();
  }

}

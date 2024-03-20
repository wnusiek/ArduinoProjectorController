void setup() {
  Serial.begin(9600);
  
/*
Przyciski   inputPins  Diody       outputPins
Power       3          zielona     8
Computer 1  4          czerwona    9
Computer 2  5          żółta       10
HDMI        6          niebieska   11
Video       7          biała       12
*/

  int outputPins [] = {8,9,10,11,12};
  for (int i = 0; i < sizeof(outputPins)/sizeof(outputPins[0]); i++){
    pinMode(outputPins[i], OUTPUT);     //USTAWIENIE WYJŚĆ SYGNALIZACYJNYCH
    digitalWrite(outputPins[i], LOW);   //WYŁĄCZENIE DIOD
  }

  int inputPins [] = {3,4,5,6,7};
  for (int i = 0; i < sizeof(inputPins)/sizeof(inputPins[0]); i++){
    pinMode(inputPins[i], INPUT_PULLUP);    //USTAWIENIE PRZYCISKÓW
  }
  
}

class Button {
private:
  String name;
  int input;
  String projectorCommand;
  int output;

public:
  Button(String name, int input, String projectorCommand, int output) {
    this->name = name;
    this->input = input;
    this->projectorCommand = projectorCommand;
    this->output = output;
  }

  void checkIfButtonPressed() {
    if (digitalRead(this->input) == LOW) {
      digitalWrite(this->output, HIGH);
      Serial.println(this->projectorCommand);
      delay(300);
    } else {
      digitalWrite(this->output, LOW);
      delay(10);
    }
  };

};
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
  
  Button power("Power", 3, returnPowerCommand(), 8);
  Button computer1("Computer 1 D-SUB VGA", 4, "SOURCE 11\r\n", 9);
  Button computer2("Computer 2 D-SUB VGA", 5, "SOURCE 21\r\n", 10);
  Button hdmi("HDMI", 6, "SOURCE 30\r\n", 11);
  Button video("Video", 7, "SOURCE 41\r\n", 12);
  Button buttons[] = {power, computer1, computer2, hdmi, video};
  for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++) {
    
    buttons[i].checkIfButtonPressed();
  }

}

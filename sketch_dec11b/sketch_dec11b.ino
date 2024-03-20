void setup() {
  Serial.begin(9600);
/*

Diody       outputPins
zielona     8
czerwona    9
żółta       10
niebieska   11
biała       12

Przyciski   inputPins
Power       3
Computer 1  4
Computer 2  5
HDMI        6
Video       7

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
      delay(200);
    } else {
      digitalWrite(this->output, LOW);
    }
  };

};

  boolean isOn = false;

  String returnPowerCommand() {
    if (isOn == true) {
      isOn = false;
      return "PWR OFF\r\n";
    } 
    if (isOn == false) {
      isOn = true;
      return "PWR ON\r\n";
    }
  };

  Button power("Power", 3, returnPowerCommand(), 8);
  Button computer1("Computer 1 D-SUB VGA", 4, "SOURCE 11\r\n", 9);
  Button computer2("Computer 2 D-SUB VGA", 5, "SOURCE 21\r\n", 10);
  Button hdmi("HDMI", 6, "SOURCE 30\r\n", 11);
  Button video("Video", 7, "SOURCE 41\r\n", 12);
  Button buttons[] = {power, computer1, computer2, hdmi, video};

void loop() {

  for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++) {
    buttons[i].checkIfButtonPressed();
  }

}

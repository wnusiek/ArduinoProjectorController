void setup() {
Serial.begin(9600);

//SYGNALIZACJA
pinMode(8, OUTPUT); //Dioda jako wyjście (ZIELONA)
pinMode(9, OUTPUT); //Dioda jako wyjście (CZERWONA)
pinMode(10, OUTPUT); //Dioda jako wyjście (ŻÓŁTA)
pinMode(11, OUTPUT); //Dioda jako wyjście (NIEBIESKA)
pinMode(12, OUTPUT); //Dioda jako wyjście (BIAŁA)

digitalWrite(8, LOW); //Wyłączenie diody
digitalWrite(9, LOW); //Wyłączenie diody
digitalWrite(10, LOW); //Wyłączenie diody
digitalWrite(11, LOW); //Wyłączenie diody
digitalWrite(12, LOW); //Wyłączenie diody

//PRZYCISKI
pinMode(3, INPUT_PULLUP); //POWER ON/OFF
pinMode(4, INPUT_PULLUP); //SOURCE COMPUTER 1
pinMode(5, INPUT_PULLUP); //SOURCE COMPUTER 1
pinMode(6, INPUT_PULLUP); //SOURCE HDMI
pinMode(7, INPUT_PULLUP); //SOURCE VIDEO
}

boolean isOn = false;
void loop() {

//POWER ON/OFF
if (digitalRead(3) == LOW) { //Jeśli przycisk wciśnięty
digitalWrite(8, HIGH); //Włącz diodę zieloną
  if (isOn == true){
  Serial.println("PWR OFF\r\n");
  delay(200);
  isOn = false
  } else {
  Serial.println("PWR ON\r\n");
  delay(200); 
  isOn = true;
  }
} else { //Jeśli warunek  przycisk nie jest wciśnięty
digitalWrite(8, LOW); //Wyłącz diodę
}

//SOURCE COMPUTER 1
if (digitalRead(4) == LOW) { //Jeśli przycisk wciśnięty
digitalWrite(9, HIGH); //Włącz diodę żółtą
Serial.println("SOURCE 11\r\n");
delay(200);
} else { //Jeśli warunek  przycisk nie jest wciśnięty
digitalWrite(9, LOW); //Wyłącz diodę
}

//SOURCE COMPUTER 2
if (digitalRead(5) == LOW) { //Jeśli przycisk wciśnięty
digitalWrite(10, HIGH); //Włącz diodę żółtą
Serial.println("SOURCE 21\r\n");
delay(200);
} else { //Jeśli warunek  przycisk nie jest wciśnięty
digitalWrite(10, LOW); //Wyłącz diodę
}

//SOURCE HDMI
if (digitalRead(6) == LOW) { //Jeśli przycisk wciśnięty
digitalWrite(11, HIGH); //Włącz diodę czerwoną
Serial.println("SOURCE 30\r\n");
delay(200);
} else { //Jeśli warunek  przycisk nie jest wciśnięty
digitalWrite(11, LOW); //Wyłącz diodę
}

//SOURCE VIDEO 
if (digitalRead(7) == LOW) { //Jeśli przycisk wciśnięty
digitalWrite(12, HIGH); //Włącz diodę czerwoną
Serial.println("SOURCE 41\r\n");
delay(200);
} else { //Jeśli warunek  przycisk nie jest wciśnięty
digitalWrite(12, LOW); //Wyłącz diodę
}


}

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  inputString.reserve(50);
   lcd.print("Tester czytnikow");
   lcd.setCursor(0,1);
   lcd.print("Wybierz czytnik");
}

void loop() {
  serialEvent();
   if (stringComplete) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(inputString);
    lcd.setCursor(0,1);
    lcd.print("Znaki: ");
    lcd.print(inputString.length()-1);
    inputString = "";
    stringComplete = false;
  }
   
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\r') {
      stringComplete = true;
    }
  }
}


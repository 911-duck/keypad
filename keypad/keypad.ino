#include "keypad.h"

const int pinsKeypad[2][4] = {
  {6,7,8,9},
  {5,4,3,2}
};

Keypad keypad = Keypad(pinsKeypad[0], pinsKeypad[1]);

void setup() {
  Serial.begin(9600);
}

String output = "";

void loop() {
  char n = keypad.readChar();
  if(n != '_'){
    output+=n;
    Serial.println("");
    Serial.println(output);
    Serial.println("");
  }
}

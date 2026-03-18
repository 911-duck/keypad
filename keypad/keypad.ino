#include "keypad.h" // класс для клавиатуры

const int pinsKeypad[2][4] = {
  {6,7,8,9},
  {5,4,3,2}
}; // пины матрицы клавиатуры 

Keypad keypad = Keypad(pinsKeypad[0], pinsKeypad[1]); // вызов

void setup() {
  Serial.begin(9600); // для откладки
}

String output = ""; // результат

void loop() {
  char n = keypad.readChar(); // получаем символ
  
  if(n != '_' && n != '<'){ // если разрешённый символ
    output+=n;
    Serial.println("");
    Serial.println(output);
    Serial.println("");
  }

  if(n == '<'){ // удаление
    output.remove(output.length()-1);
  }
}

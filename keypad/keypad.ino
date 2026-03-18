#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // подключение библеотек для использования жк дислея

#include "keypad.h"  // класс для клавиатуры

const int pinsKeypad[2][4] = {
  { 6, 7, 8, 9 },
  { 5, 4, 3, 2 }
};  // пины матрицы клавиатуры

LiquidCrystal_I2C lcd(0x27, 16, 2);
Keypad keypad = Keypad(pinsKeypad[0], pinsKeypad[1]);  // создание инстансов классов

void setup() {
  Serial.begin(9600);  // для откладки

  lcd.init();
  lcd.backlight();  // иницализация жк дисплея
}

String output = "";  // результат
String newS = "";

void loop() {
  char n = keypad.readChar();  // получаем символ

  if (n != '_' && n != '<') {  // если разрешённый символ
    output += n;
    Serial.println("");
    Serial.println(output);
    Serial.println("");

    lcd.clear();
  }

  if (n == '<') {  // удаление
    newS = "";
    for(int i = 0; i < output.length()-1; i++){
      newS += output[i];
    }
    output = newS;
    lcd.clear();
  }
  
  lcd.setCursor(0, 0);
  lcd.print(output);  // вывод на дисплей результат
}

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // подключение библеотек для использования жк дислея

#include "keypad.h" // класс для клавиатуры

const int pinsKeypad[2][4] = {
  {6,7,8,9},
  {5,4,3,2}
}; // пины матрицы клавиатуры 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
Keypad keypad = Keypad(pinsKeypad[0], pinsKeypad[1]); // создание инстансов классов

void setup() {
  Serial.begin(9600); // для откладки

  lcd.init(); 
  lcd.backlight(); // иницализация жк дисплея   
}

String output = ""; // результат

void loop() {
  char n = keypad.readChar(); // получаем символ
  
  if(n != '_' && n != '<'){ // если разрешённый символ
    output+=n;
    Serial.println("");
    Serial.println(output);
    Serial.println("");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(output); // вывод на дисплей результат
  }

  if(n == '<'){ // удаление
    output.remove(output.length()-1);
  }
}

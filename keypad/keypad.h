// класс - Keypad
// методы :
// .read(int h, int w);
// .readChar();
// вызов : 
// Keypad "name" = Keypad(int pinsA[4], int pinsB[4]);

#pragma once

class Keypad {
  public:
  Keypad(int pinsA[4], int pinsB[4]); // конструктор класса
  int read(int h, int w); // чтение нажатой кнопки h и w - это область виденья
  char readChar(); // чтение символа
  private:
  int _pinsA[4]; // пины матрицы
  int _pinsB[4];
  const char _KEYS_TO_CHAR[9][4]={ // символы
    {'1','A','B','C'},
    {'2','D','E','F'},
    {'3','G','H','I'},
    {'4','J','K','L'},
    {'5','M','N','O'},
    {'6','P','Q','R'},
    {'7','S','T','U'},
    {'8','V','W','X'},
    {'9','Y','Z','.'},
    {'*','+','-','$'},
    {'0',' ','<','/'}, // '<' - удаление, ' ' - пробел
    {'@','#',';',':'},
  };
};

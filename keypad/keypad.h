#pragma once

class Keypad {
  public:
  Keypad(int pinsA[4], int pinsB[4]);
  int read(int h, int w);
  char readChar();
  private:
  int _pinsA[4];
  int _pinsB[4];
  const char _KEYS_TO_CHAR[9][4]={
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
    {'0',' ','-','/'},
    {'@','#',';',':'},
  };
};

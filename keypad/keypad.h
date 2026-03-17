#pragma once

class Keypad {
  public:
  Keypad(int pinsA[4], int pinsB[4]);
  int read(int maxS);
  char readChar();
  private:
  int _pinsA[4];
  int _pinsB[4];
  const char _KEYS_TO_CHAR[9][3]={
    {'A','B','C'},
    {'D','E','F'},
    {'G','H','I'},
    {'J','K','L'},
    {'M','N','O'},
    {'P','Q','R'},
    {'S','T','U'},
    {'V','W','X'},
    {'Y','Z','.'},
  };
};

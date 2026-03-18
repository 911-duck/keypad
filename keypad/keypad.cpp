#include "HardwareSerial.h"
#include "Arduino.h"
#include "keypad.h"

Keypad::Keypad(int pinsA[4], int pinsB[4]) {
  for (int i = 0; i < 4; i++) {
    _pinsA[i] = pinsA[i];
    _pinsB[i] = pinsB[i];
  }
}

int Keypad::read(int h, int w) {
  for (int i = 0; i < h; i++) {
    pinMode(_pinsA[i], OUTPUT);
    pinMode(_pinsB[i], INPUT_PULLUP);

    digitalWrite(_pinsA[i], HIGH);
  }

  int x = 0;
  for (int i = 0; i < h; i++) {
    digitalWrite(_pinsA[i], LOW);
    for (int j = 0; j < maxS; j++) {
      if (!digitalRead(_pinsB[j])) x = i + 1;
    }
    digitalWrite(_pinsA[i], HIGH);
  }

  for (int i = 0; i < w; i++) {
    pinMode(_pinsB[i], OUTPUT);
    pinMode(_pinsA[i], INPUT_PULLUP);

    digitalWrite(_pinsB[i], HIGH);
  }

  int y = 0;
  for (int i = 0; i < w; i++) {
    digitalWrite(_pinsB[i], LOW);
    for (int j = 0; j < maxS; j++) {
      if (!digitalRead(_pinsA[j])) y = i;
    }
    digitalWrite(_pinsB[i], HIGH);
  }

  return x + y * h;
}

char Keypad::readSpecialChar(int read){
  
}

char Keypad::readChar() {
  int readB = read(3,4);

  if (!readB) return '_';

  while (read(3,4));

  const int y = readB - 1;
  int n = 0;

  char result;
  long long prev = millis();
  while (millis() - prev < 1000) {
    if (read(3,4) == readB) {
      n = (n + 1) % 4;
      delay(500);
      prev = millis();
    }else if(read(3,4) != 0){
      break;
    }
    const int x = n;
    result = _KEYS_TO_CHAR[y][x];
  }

  return result;
}
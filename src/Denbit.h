#ifndef DENBIT_H
#define DENBIT_H

#include "Arduino.h"

#define DENBIT_GREEN     13 // D7
#define DENBIT_RED       12 // D6
#define DENBIT_RGB_RED   15 // D8
#define DENBIT_RGB_GREEN 14 // D5
#define DENBIT_RGB_BLUE  10 // SD3
#define DENBIT_SW1 2
#define DENBIT_SW2 16

class Denbit
{
  public:
    Denbit();
  private:
    int _mode;
};

#endif

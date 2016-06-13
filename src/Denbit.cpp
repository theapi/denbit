#include "Arduino.h"
#include "Denbit.h"

Denbit::Denbit()
{
  // Single LEDs
  pinMode(DENBIT_GREEN, OUTPUT);
  pinMode(DENBIT_RED, OUTPUT);

  // RGB led
  pinMode(DENBIT_RGB_RED, OUTPUT);
  pinMode(DENBIT_RGB_GREEN, OUTPUT);
  pinMode(DENBIT_RGB_BLUE, OUTPUT);

  // Switches
  pinMode(DENBIT_SW1, INPUT_PULLUP);
  pinMode(DENBIT_SW2, INPUT); // No pullup on pin 16


  digitalWrite(DENBIT_GREEN, LOW);
  digitalWrite(DENBIT_RED, LOW);

  digitalWrite(DENBIT_RGB_RED, LOW);
  digitalWrite(DENBIT_RGB_GREEN, LOW);
  digitalWrite(DENBIT_RGB_BLUE, LOW);
}

#pragma once
#include <PCF8575.h>

class GPIO {
  public:
    static void initialize() {
      while (!PCF.begin()) delay(1);
    }

    static void pinMode(uint8_t pin, uint8_t mode, uint8_t outputStart = HIGH) {
      PCF.pinMode(pin, mode, outputStart);
    }

    static bool digitalWrite(uint8_t pin, uint8_t value) {
      return PCF.digitalWrite(pin, value);
    }

    static uint8_t digitalRead(uint8_t pin) {
      return PCF.digitalRead(pin);
    }

  private:
    static PCF8575 PCF;
};

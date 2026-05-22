#pragma once
#include <PCF8575.h>

class GPIO {
  public:
    static void initialize() {
      while (!PCF.begin()) {
        Serial.println("Initializing PCF");
        delay(10);
      }
    }

    static void digitalWrite(uint8_t pin, uint8_t value) {
      PCF.write(pin, value);
    }

    static uint8_t digitalRead(uint8_t pin) {
      return PCF.read(pin);
    }

  private:
    static PCF8575 PCF;
};
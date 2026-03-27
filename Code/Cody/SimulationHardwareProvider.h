#pragma once
#include "IHardwareProvider.h"
#include <ArduinoJson.h>

class SimulationHardwareProvider : public IHardwareProvider {
  public:
    void move(NavigationData navigationData) override {
      JsonDocument document;

      document["method"] = "Move";
      document["parameters"][0] = navigationData.leftMotorForwards;
      document["parameters"][1] = navigationData.leftMotorPwm;
      document["parameters"][2] = navigationData.rightMotorForwards;
      document["parameters"][3] = navigationData.rightMotorPwm;

      serializeJson(document, Serial);
      Serial.println();
    }
};
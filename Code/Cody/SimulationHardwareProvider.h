#pragma once
#include "IHardwareProvider.h"
#include "Task.h"
#include <ArduinoJson.h>

class SimulationHardwareProvider : public IHardwareProvider {
  public:
    void move(NavigationData navigationData) override {
      JsonDocument document;

      document["method"] = "Move";
      document["parameters"][0] = navigationData.leftMotor.forwards;
      document["parameters"][1] = navigationData.leftMotor.pwm;
      document["parameters"][2] = navigationData.rightMotor.forwards;
      document["parameters"][3] = navigationData.rightMotor.pwm;

      serializeJson(document, Serial);
      Serial.println();
    }

    virtual void moveToolhead(ToolheadData toolheadData) {
      JsonDocument document;

      document["method"] = "MoveToolhead";
      document["parameters"][0] = toolheadData.xAxisMotor.forwards;
      document["parameters"][1] = toolheadData.xAxisMotor.pwm;
      document["parameters"][2] = toolheadData.zAxisMotor.forwards;
      document["parameters"][3] = toolheadData.zAxisMotor.pwm;

      serializeJson(document, Serial);
      Serial.println();
    }
};
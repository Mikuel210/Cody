#pragma once
#include "IHardwareProvider.h"
#include "Task.h"
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

    void homeXAxisAsync() override {}
    void moveXAxisAsync(double position) override {}

    void homeYAxisAsync() override {}
    void moveYAxisAsync(double position) override {}

  private:
    void moveXAxis(bool forwards, int pwm) {
      JsonDocument document;

      document["method"] = "MoveXAxis";
      document["parameters"][0] = forwards;
      document["parameters"][1] = pwm;
    }
};
#pragma once
#include "IHardwareProvider.h"

#define L_PWM 2
#define R_PWM 4

class RobotHardwareProvider : public IHardwareProvider {
  public:
    void initialize() override {
      pinMode(L_PWM, OUTPUT);
      pinMode(R_PWM, OUTPUT);
    }

    void move(NavigationData navigationData) override {
      analogWrite(L_PWM, navigationData.leftMotorPwm); // TODO: Set direction
      analogWrite(R_PWM, navigationData.rightMotorPwm); // TODO: Set direction
    }
};
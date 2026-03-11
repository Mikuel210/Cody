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

    virtual void moveLeftMotor(int direction, int pwm) {
      analogWrite(L_PWM, pwm); // TODO: Set direction
    }

    virtual void moveRightMotor(int direction, int pwm) {
      analogWrite(R_PWM, pwm);
    }
};
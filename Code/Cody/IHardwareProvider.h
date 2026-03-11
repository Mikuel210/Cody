#pragma once
#include "Vector3.h"

class IHardwareProvider {
  public:
    virtual ~IHardwareProvider() {}
    virtual void initialize() {}

    virtual void moveLeftMotor(int direction, int pwm) {}
    virtual void moveRightMotor(int direction, int pwm) {}
};

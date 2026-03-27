#pragma once
#include "Vector3.h"

struct NavigationData {
  bool leftMotorForwards;
  int leftMotorPwm;

  bool rightMotorForwards;
  int rightMotorPwm;
};
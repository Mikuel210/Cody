#pragma once
#include <algorithm>
#include <cmath>
#include "Vector3.h"
#include "NavigationData.h"
#include "FusionData.h"
#include "PID.h"

#define KP 1
#define KI 0.25f
#define KD 2

class Navigation {
  public:
    static NavigationData getData(FusionData fusionData) {
      NavigationData navigationData;

      // Get orientation correction
      float targetOrientation = atan2(target.x - fusionData.position.x, target.y - fusionData.position.y) * (180.0 / M_PI);
      float error = targetOrientation - fusionData.orientation;

      while (error > 180.0) { error -= 360.0; targetOrientation -= 360.0; }
      while (error < -180.0) { error += 360.0; targetOrientation += 360.0; }

      double dx = target.x - fusionData.position.x;
      double dy = target.y - fusionData.position.y;
      double distance = sqrt(dx * dx + dy * dy);

      double leftPwm = 0.0;
      double rightPwm = 0.0;

      if (distance > 2)
      {
        double distancePwm = std::clamp(distance * 0.25, -255.0, 255.0) * std::clamp(1.0 - abs(error) * 0.01, 0.0, 1.0);
        leftPwm = std::clamp(distancePwm + error, -255.0, 255.0);
        rightPwm = std::clamp(distancePwm - error, -255.0, 255.0);
      }

      navigationData.leftMotorForwards = (leftPwm >= 0.0);
      navigationData.rightMotorForwards = (rightPwm >= 0.0);
      navigationData.leftMotorPwm = abs(leftPwm);
      navigationData.rightMotorPwm = abs(rightPwm);

      return navigationData;
    }

    static void setTarget(Vector3 newTarget) {
      target = newTarget;
    }

  private:
    static Vector3 target;
};
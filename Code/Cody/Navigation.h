#pragma once
#include <algorithm>
#include <cmath>
#include "Vector3.h"
#include "NavigationData.h"
#include "FusionData.h"
#include "PID.h"

#define KP 1
#define KI 0.25
#define KD 1

#define STOP_DISTANCE 1
#define ERROR_DECELERATION 0.02
#define SPEED 1

class Navigation {
  public:
    static NavigationData getData(FusionData fusionData) {
      NavigationData navigationData;

      // Get orientation correction
      float targetOrientation = atan2(target.x - fusionData.position.x, target.y - fusionData.position.y) * (180.0 / M_PI);
      float error = targetOrientation - fusionData.orientation;

      while (error > 180.0) { error -= 360.0; targetOrientation -= 360.0; }
      while (error < -180.0) { error += 360.0; targetOrientation += 360.0; }

      double distance = getDistance(fusionData.position, target);
      double leftPwm = 0.0;
      double rightPwm = 0.0;

      if (distance > STOP_DISTANCE)
      {
        double steeringAuthority = std::clamp(dmap(distance, 100.0, 2.0, 1.0, 0.0), 0.0, 1.0);
        double orientationCorrection = -orientationPid.getCorrection(error) * steeringAuthority;

        double distanceAuthority = std::clamp(1.0 - abs(orientationCorrection) * ERROR_DECELERATION, 0.0, 1.0);
        double distanceCorrection = -distancePid.getCorrection(distance) * 255.0 * SPEED / decelerationDistance;
        double distancePwm = std::clamp(distanceCorrection, -255.0, 255.0) * distanceAuthority;

        leftPwm = std::clamp(distancePwm + orientationCorrection, -255.0, 255.0);
        rightPwm = std::clamp(distancePwm - orientationCorrection, -255.0, 255.0);
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

    static void setDecelerationDistance(double distance) {
      decelerationDistance = distance;
    }

    static double getDistance(Vector3 a, Vector3 b) {
      double dx = b.x - a.x;
      double dy = b.y - a.y;
      return sqrt(dx * dx + dy * dy);
    }

  private:
    static PID orientationPid;
    static PID distancePid;
    static Vector3 target;
    static double decelerationDistance;

    static double dmap(double x, double in_min, double in_max, double out_min, double out_max) {
      return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
};
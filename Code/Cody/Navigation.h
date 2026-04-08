#pragma once
#include <algorithm>
#include <cmath>
#include "Vector3.h"
#include "NavigationTarget.h"
#include "NavigationData.h"
#include "ToolheadData.h"
#include "WheelsData.h"
#include "FusionData.h"
#include "PID.h"

// Navigation parameters
#define STOP_DISTANCE 1
#define TOOLHEAD_STOP_DISTANCE 1
#define ERROR_DECELERATION 0.02
#define STEERING_MAX_AUTHORITY 2.0

class Navigation {
  public:
    static NavigationTarget drive;
    static NavigationTarget toolhead;
    static NavigationTarget wheels;

    static NavigationData getData(FusionData fusionData) {
      NavigationData navigationData;

      // Get orientation correction
      float targetOrientation = atan2(drive.target.x - fusionData.position.x, drive.target.y - fusionData.position.y) * (180.0 / M_PI);
      float error = targetOrientation - fusionData.orientation;

      while (error > 180.0) { error -= 360.0; targetOrientation -= 360.0; }
      while (error < -180.0) { error += 360.0; targetOrientation += 360.0; }

      // Get distance correction
      double distance = getDistance(fusionData.position, drive.target);
      double leftPwm, rightPwm;

      if (distance > STOP_DISTANCE)
      {
        double steeringAuthority = std::clamp(dmap(distance, 100.0, STEERING_MAX_AUTHORITY, 1.0, 0.0), 0.0, 1.0);
        double orientationCorrection = -orientationPid.getCorrection(error) * steeringAuthority;

        double distanceAuthority = std::clamp(1.0 - abs(orientationCorrection) * ERROR_DECELERATION, 0.0, 1.0);
        double distancePwm = correctionToPwm(-distancePid.getCorrection(distance), drive) * distanceAuthority;

        leftPwm = std::clamp(distancePwm + orientationCorrection, -255.0, 255.0);
        rightPwm = std::clamp(distancePwm - orientationCorrection, -255.0, 255.0);
      }

      // Construct navigation data
      navigationData.leftMotor = MotorData(leftPwm >= 0.0, abs(leftPwm));
      navigationData.rightMotor = MotorData(rightPwm >= 0.0, abs(rightPwm));

      return navigationData;
    }

    static ToolheadData getToolheadData(FusionData fusionData) {
      ToolheadData toolheadData;

      // Get toolhead correction
      xAxisPid.setSetpoint(toolhead.target.x);
      zAxisPid.setSetpoint(toolhead.target.z);

      double xAxisPwm = correctionToPwm(xAxisPid.getCorrection(fusionData.toolheadPosition.x), toolhead);
      double zAxisPwm = correctionToPwm(zAxisPid.getCorrection(fusionData.toolheadPosition.x), toolhead);

      // Construct toolhead data
      toolheadData.xAxisMotor = MotorData(xAxisPwm >= 0.0, abs(xAxisPwm));
      toolheadData.zAxisMotor = MotorData(zAxisPwm >= 0.0, abs(zAxisPwm));

      return toolheadData;
    }

    static WheelsData getWheelsData(FusionData fusionData) {
      WheelsData wheelsData;

      // Get wheels correction
      wheelsPid.setSetpoint(wheels.target.z);
      double pwm = correctionToPwm(wheelsPid.getCorrection(fusionData.wheelsPosition), wheels); //TODO wheelsPosition

      // Construct wheels data
      wheelsData.wheelsMotor = MotorData(pwm >= 0.0, abs(pwm));
      return wheelsData;
    }

    static double getDistance(Vector3 a, Vector3 b) {
      double dx = b.x - a.x;
      double dy = b.y - a.y;
      return sqrt(dx * dx + dy * dy);
    }

  private:
    static PID orientationPid;
    static PID distancePid;
    static PID xAxisPid;
    static PID zAxisPid;
    static PID wheelsPid;

    static double dmap(double x, double in_min, double in_max, double out_min, double out_max) {
      return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    static double correctionToPwm(double correction, NavigationTarget target) {
      return std::clamp(correction * 255.0 / target.decelerationDistance, -255.0, 255.0);
    }
};
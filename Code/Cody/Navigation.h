#pragma once
#include "Vector3.h"
#include "NavigationData.h"
#include "FusionData.h"

#define KP 1
#define KI 0.25f
#define KD 2

class Navigation {
  public:
    NavigationData getData(FusionData fusionData) {
      NavigationData navigationData;

      // TODO
      float orientationCorrection = orientationPID.getCorrection(fusionData.orientation);
      float positionCorrection = orientationPID.getCorrection(fusionData.position);

      navigationData.leftMotorPwm = positionCorrection + orientationCorrection;
      navigationData.rightMotorPwm = positionCorrection - orientationCorrection;
    }

    void setTarget(Vector3 newTarget) {
      target = newTarget;
    }

  private:
    Vector3 target;
    
    PID orientationPID = PID(KP, KI, KD);
    PID positionPID = PID(KP, KI, KD);
};
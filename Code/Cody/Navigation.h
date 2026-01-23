#pragma once
#include "Vector3.h"
#include "NavigationData.h"
#include "FusionData.h"

class Navigation {
  public:
    NavigationData getData(FusionData fusionData) {
      
    }

    void setTarget(Vector3 newTarget) {
      target = newTarget;
    }

  private:
    Vector3 target;
};
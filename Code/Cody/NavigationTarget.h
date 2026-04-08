#pragma once
#include "Vector3.h"

struct NavigationTarget {
  Vector3 target;
  double decelerationDistance;

  virtual void setTarget(Vector3 target_) {
    target = target_;
  }
  
  void setDecelerationDistance(double decelerationDistance_) { 
    decelerationDistance = decelerationDistance_; 
  }
};
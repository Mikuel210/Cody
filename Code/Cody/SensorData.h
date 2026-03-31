#pragma once
#include "Vector3.h"

struct SensorData {
  Vector3 acceleration;
  Vector3 gyroscope;
  Vector3 magnetometer;

  int leftPulses;
  int rightPulses;
  int xAxisPulses;
  int zAxisPulses;
  int wheelsPulses;
  int millPulses;
};
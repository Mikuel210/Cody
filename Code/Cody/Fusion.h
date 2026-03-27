#pragma once
#include "Vector3.h"
#include "SensorData.h"
#include "FusionData.h"
#include <SensorFusion.h>

#define TRAVEL_PER_REVOLUTION_MM 276.460153516
#define TICKS_PER_REVOLUTION 16.0
#define DISTANCE_BETWEEN_WHEELS_MM 228.0

class Fusion {
  public:
    static FusionData getData(SensorData sensorData) {
      // Get orientation
      FusionData fusionData;
      deltat = fusion.deltatUpdate();

      fusion.MahonyUpdate(
        sensorData.gyroscope.x, sensorData.gyroscope.y, sensorData.gyroscope.z, 
        sensorData.acceleration.x, sensorData.acceleration.y, sensorData.acceleration.z, 
        sensorData.magnetometer.x, sensorData.magnetometer.y, sensorData.magnetometer.z, deltat
      );

      float imuOrientation = fusion.getRoll();

      // Get position
      double leftDistanceMm = (sensorData.leftPulses - previousLeftPulses) * TRAVEL_PER_REVOLUTION_MM / TICKS_PER_REVOLUTION;
      double rightDistanceMm = (sensorData.rightPulses - previousRightPulses) * TRAVEL_PER_REVOLUTION_MM / TICKS_PER_REVOLUTION;
      double deltaDistanceMm = (leftDistanceMm + rightDistanceMm) / 2.0;

      double deltaOrientation = (leftDistanceMm - rightDistanceMm) / DISTANCE_BETWEEN_WHEELS_MM * (180.0 / M_PI);
      double orientation = previousOrientation + deltaOrientation;
      double averageOrientation = previousOrientation + deltaOrientation / 2.0;

      double deltaX = deltaDistanceMm * sin(averageOrientation * DEG_TO_RAD);
      double deltaY = deltaDistanceMm * cos(averageOrientation * DEG_TO_RAD);

      fusionData.orientation = orientation; // TODO: Fuse with IMU orientation
      fusionData.position = Vector3(previousPosition.x + deltaX, previousPosition.y + deltaY, 0);

      previousLeftPulses = sensorData.leftPulses;
      previousRightPulses = sensorData.rightPulses;
      previousPosition = fusionData.position;
      previousOrientation = orientation;

      return fusionData;
    }

  private:
    static float deltat;
    static SF fusion;
    
    static int previousLeftPulses;
    static int previousRightPulses;
    static double previousOrientation;
    static Vector3 previousPosition;
};
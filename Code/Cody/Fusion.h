#pragma once
#include "Vector3.h"
#include "SensorData.h"
#include "FusionData.h"
#include <SensorFusion.h>

// Fusion parameters
#define TRAVEL_PER_REVOLUTION_MM 276.460153516
#define X_AXIS_MM_PER_REVOLUTION 43.9822971503
#define Z_AXIS_MM_PER_REVOLUTION 56.5486677646
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

      // Get toolhead position
      double toolheadDeltaX = (sensorData.xAxisPulses - previousXAxisPulses) * X_AXIS_MM_PER_REVOLUTION / TICKS_PER_REVOLUTION;
      double toolheadDeltaZ = (sensorData.zAxisPulses - previousZAxisPulses) * Z_AXIS_MM_PER_REVOLUTION / TICKS_PER_REVOLUTION;


      // Construct fusion data
      fusionData.orientation = orientation; // TODO: Fuse with IMU orientation
      fusionData.position = Vector3(previousPosition.x + deltaX, previousPosition.y + deltaY, 0);
      fusionData.toolheadPosition = Vector3(previousToolheadPosition.x + toolheadDeltaX, 0, previousToolheadPosition.z + toolheadDeltaZ);

      Serial.print(fusionData.toolheadPosition.x); Serial.print(" | ");
      Serial.print(fusionData.toolheadPosition.z); Serial.print(" | ");

      previousPosition = fusionData.position;
      previousToolheadPosition = fusionData.toolheadPosition;
      previousOrientation = orientation;

      previousLeftPulses = sensorData.leftPulses;
      previousRightPulses = sensorData.rightPulses;
      previousXAxisPulses = sensorData.xAxisPulses;
      previousZAxisPulses = sensorData.zAxisPulses;

      return fusionData;
    }

  private:
    static float deltat;
    static SF fusion;
    static Vector3 previousPosition;
    static Vector3 previousToolheadPosition;
    static double previousOrientation;
    
    static int previousLeftPulses;
    static int previousRightPulses;
    static int previousXAxisPulses;
    static int previousZAxisPulses;
};
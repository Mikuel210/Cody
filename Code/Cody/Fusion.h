#pragma once
#include "Vector3.h"
#include "SensorData.h"
#include "FusionData.h"
#include "Plotter.h"
#include <SensorFusion.h>

#define TRAVEL_PER_REVOLUTION_MM 1
#define TICKS_PER_REVOLUTION 1
#define DISTANCE_BETWEEN_WHEELS_MM 1

class Fusion {
  public:
    FusionData getData(SensorData sensorData) {
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
      float leftDistanceMm = (sensorData.leftPulses - previousLeftPulses) / TICKS_PER_REVOLUTION * TRAVEL_PER_REVOLUTION_MM;
      float rightDistanceMm = (sensorData.leftPulses - previousLeftPulses) / TICKS_PER_REVOLUTION * TRAVEL_PER_REVOLUTION_MM;
      float deltaDistanceMm = (leftDistanceMm + rightDistanceMm) / 2;

      float deltaOrientation = (rightDistanceMm - leftDistanceMm) / DISTANCE_BETWEEN_WHEELS_MM;
      float orientation = previousOrientation = deltaOrientation;

      float deltaX = deltaDistanceMm * cos(orientation);
      float deltaY = deltaDistanceMm * sin(orientation);

      fusionData.orientation = orientation; // TODO: Fuse with IMU orientation
      fusionData.position = Vector3(previousPosition.x + deltaX, previousPosition.y + deltaY, 0);

      previousLeftPulses = sensorData.leftPulses;
      previousRightPulses = sensorData.rightPulses;
      previousOrientation = odometryOrientation;

      return fusionData;
    }

  private:
    float deltat;
    SF fusion;

    int previousLeftPulses;
    int previousRightPulses;
    float previousOrientation;
    Vector3 previousPosition;
};
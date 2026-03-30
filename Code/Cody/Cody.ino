#define SIMULATION
#include "Fusion.h"
#include "Navigation.h"
#include "Vector3.h"
#include "Pursuit.h"

#ifdef SIMULATION
  #include "SimulationDataProvider.h"
  #include "SimulationHardwareProvider.h"
  SimulationDataProvider dataProvider;
  SimulationHardwareProvider hardwareProvider;
#else
  #include "SensorDataProvider.h"
  #include "RobotHardwareProvider.h"
  SensorDataProvider dataProvider;
  RobotHardwareProvider hardwareProvider;
#endif

// Setup

void setup() {
  Serial.begin(1000000);
  dataProvider.initialize();
  hardwareProvider.initialize();
  Pursuit::initialize(dataProvider, hardwareProvider);

  go();
}

void loop() { }

void go() {
  
  Pursuit::addPoint(Vector3(0, 5'000));
  Pursuit::addPoint(Vector3(5'000, 5'000));
  Pursuit::addPoint(Vector3(5'000, 10'000));
  Pursuit::addPoint(Vector3(0, 10'000));
  Pursuit::addPoint(Vector3(0, 15'000));
  Pursuit::followPathAsync(1'000);
  
/*
  Pursuit::addPoint(Vector3(0, 700));
  Pursuit::addPoint(Vector3(2000, 700));
  Pursuit::addPoint(Vector3(2000, 0));
  Pursuit::addPoint(Vector3(0, 0));
  Pursuit::followPathAsync(200);*/
}
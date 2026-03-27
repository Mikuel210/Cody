#define SIMULATION
#include "Fusion.h"
#include "Navigation.h"
#include "Vector3.h"

// Navigation classes

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

// Pursuit pursuit = Pursuit(dataProvider, hardwareProvider);

// Initialize providers

void setup() {
  Serial.begin(1000000);
  dataProvider.initialize();
  hardwareProvider.initialize();

  Navigation::setTarget(Vector3(10'000, 5'000, 0));
}

void loop() {
  unsigned long msStart = millis();

  SensorData sensorData = dataProvider.getData();
  FusionData fusionData = Fusion::getData(sensorData);
  NavigationData navigationData = Navigation::getData(fusionData);
  hardwareProvider.move(navigationData);

  delay(1000.0 / 60.0 - (millis() - msStart));
}
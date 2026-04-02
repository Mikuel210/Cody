// Global parameters
#define SIMULATION
#define BAUD_RATE 1000000

// Include dependencies
#include "Cody.h"
#include "Program.h"

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
  Serial.begin(BAUD_RATE);
  dataProvider.initialize();
  hardwareProvider.initialize();
  
  Cody::initialize(dataProvider, hardwareProvider);
  Program::go();
}

void loop() { }
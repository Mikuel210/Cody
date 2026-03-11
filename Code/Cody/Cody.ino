#include "SensorDataProvider.h"
#include "Fusion.h"
#include "Navigation.h"
#include "RobotHardwareProvider.h"
#include "Vector3.h"

SensorDataProvider dataProvider;
RobotHardwareProvider hardwareProvider;
Fusion fusion;
Navigation navigation;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dataProvider.initialize();
  hardwareProvider.initialize();

  navigation.setTarget(Vector3(100, 100, 0));
}

void loop() {
  SensorData sensorData = dataProvider.getData();
  FusionData fusionData = fusion.getData(sensorData);
  NavigationData navigationData = navigation.getData(fusionData);

  hardwareProvider.moveLeftMotor(navigationData.leftMotorPwm);
  hardwareProvider.moveRightMotor(navigationData.rightMotorPwm);
}
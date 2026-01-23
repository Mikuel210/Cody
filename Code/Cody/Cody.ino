#include "SensorDataProvider.h"

SensorDataProvider dataProvider;
Fusion fusion;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dataProvider.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  SensorData sensorData = dataProvider.getData();
  FusionData fusionData = fusion.getData(sensorData);
}

#pragma once
#include "IDataProvider.h"
#include "Vector3.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class SimulationDataProvider : public IDataProvider {
  public:
    SensorData getData() override {
      SensorData data;
      JsonDocument document;

      if (!Serial.available()) return previousData;

      String json = Serial.readStringUntil('\n');
      DeserializationError error = deserializeJson(document, json);

      if (error) return previousData;

      data.acceleration = Vector3(document["acceleration"][0], document["acceleration"][1], document["acceleration"][2]);
      data.gyroscope = Vector3(document["gyroscope"][0], document["gyroscope"][1], document["gyroscope"][2]);
      data.magnetometer = Vector3(document["magnetometer"][0], document["magnetometer"][1], document["magnetometer"][2]);

      data.leftPulses = document["leftPulses"];
      data.rightPulses = document["rightPulses"];
      data.xPulses = document["xPulses"];
      data.zPulses = document["zPulses"];
      data.wheelsPulses = document["wheelsPulses"];
      data.millPulses = document["millPulses"];

      previousData = data;
      return data;
    }

  private:
    SensorData previousData;
};
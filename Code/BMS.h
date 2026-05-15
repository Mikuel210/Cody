#pragma once
#include "IDataProvider.h"
#include "IHardwareProvider.h"
#include "Fusion.h"
#include "Task.h"
#include "TaskArgs.h"

// BMS parameters
#define BMS_HZ 1
#define VOLTAGE_THRESHOLD 3.4
#define BMS_FREQUENCY 440

class BMS {
  public:
    static void initialize(IDataProvider& dataProvider_, IHardwareProvider& hardwareProvider_) {
      dataProvider = &dataProvider_;
      hardwareProvider = &hardwareProvider_;

      Task* task = new Task("bms", bmsTask);
      TaskArgs* args = new TaskArgs();
      args->task = task;
      task->start(args);
    }

  private:
    static IDataProvider* dataProvider;
    static IHardwareProvider* hardwareProvider;

    static void bmsTask(void* task) {
      TaskArgs* args = (TaskArgs*)task;

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);

        if (fusionData.voltage <= VOLTAGE_THRESHOLD)
          hardwareProvider->toneBuzzer(BMS_FREQUENCY, 1000.0 / BMS_HZ / 2);

        vTaskDelay(max(1000.0 / BMS_HZ - (millis() - msStart), 0.0));
      }

      args->task->stop();
      delete args;
    }
};

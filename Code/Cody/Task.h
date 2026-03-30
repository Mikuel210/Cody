#pragma once
#include <Arduino.h>

class Task {
  public:
    Task(const char* name_, void (*function_)(void*))
      : name(name_), function(function_) {}

    void await() {
      while (!(*finished)) delay(1);
    }

    void start(void* arg = NULL) {
      xTaskCreatePinnedToCore(function, name, 10000, arg, 1, &handle, 1);
    }

    void stop() {
      if (handle == NULL) return;

      vTaskDelete(handle);
      handle = NULL;
      *finished = true;
    }

  private:
    TaskHandle_t handle = NULL;
    volatile bool* finished = new bool(false);
    const char* name;
    void (*function)(void*);
};
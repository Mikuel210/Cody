#pragma once
#include "IDataProvider.h"
#include "IHardwareProvider.h"
#include "SensorData.h"
#include "FusionData.h"
#include "Fusion.h"
#include "Navigation.h"
#include "NavigationTarget.h"
#include "NavigationData.h"
#include "Pursuit.h"
#include "PursuitData.h"
#include "Task.h"
#include "TaskArgs.h"
#include <vector>

// Task parameters
#define HZ 60.0

class Cody {
  public:
    static void initialize(IDataProvider& dataProvider_, IHardwareProvider& hardwareProvider_) {
      dataProvider = &dataProvider_;
      hardwareProvider = &hardwareProvider_;
    }

    // Drive
    static Task* moveAsync(double x, double y) {
      Task* task = new Task("move", moveTask);
      TargetArgs* args = new TargetArgs();

      args->task = task;
      args->target = new Vector3(x, y);
      args->positionMember = &FusionData::position;
      args->navigationTarget = &Navigation::drive;
      args->moveFunction = &moveRobot;

      task->start(args);
      return task;
    }

    static void addPathPoint(double x, double y) {
      Vector3 point = Vector3(x, y);
      pathData.points.push_back(point);
    }

    static Task* followPathAsync(double lookaheadDistance) {
      Task* task = new Task("followPath", followPathTask);
      FollowPathArgs* args = new FollowPathArgs();
      pathData.lookaheadDistance = lookaheadDistance;

      args->task = task;
      args->data = &pathData;
      args->positionMember = &FusionData::position;
      args->navigationTarget = &Navigation::drive;
      args->moveFunction = &moveRobot;

      task->start(args);
      return task;
    }

    // Toolhead
    static Task* moveToolheadAsync(double x, double z) {
      Task* task = new Task("moveToolhead", moveTask);
      TargetArgs* args = new TargetArgs();

      args->task = task;
      args->target = new Vector3(x, z);
      args->positionMember = &FusionData::toolheadPosition;
      args->navigationTarget = &Navigation::toolhead;
      args->moveFunction = &moveToolhead;

      task->start(args);
      return task;
    }

    static void addToolheadPathPoint(double x, double y) {
      Vector3 point = Vector3(x, y);
      toolheadPathData.points.push_back(point);
    }

    static Task* followToolheadPathAsync(double lookaheadDistance) {
      FollowPathArgs* args = new FollowPathArgs();
      Task* task = new Task("followToolheadPath", followPathTask);
      pathData.lookaheadDistance = lookaheadDistance;

      args->task = task;
      args->data = &toolheadPathData;
      args->positionMember = &FusionData::toolheadPosition;
      args->navigationTarget = &Navigation::toolhead;
      args->moveFunction = &moveToolhead;

      task->start(args);
      return task;
    }

  private:
    static IDataProvider* dataProvider;
    static IHardwareProvider* hardwareProvider;
    static PursuitData pathData;
    static PursuitData toolheadPathData;

    // Move
    using PositionMember = Vector3 (FusionData::*);
    using MoveFunction = void (*)(FusionData);

    struct TargetArgs : TaskArgs {
      Vector3* target;
      PositionMember positionMember;
      NavigationTarget* navigationTarget;
      MoveFunction moveFunction;
    };

    static void moveTask(void* task) {
      TargetArgs* args = (TargetArgs*)task;
      Vector3* target = args->target;
      args->navigationTarget->setTarget(*target);

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);
        Vector3 position = fusionData.*(args->positionMember);

        double distance = Navigation::getDistance(position, *target);
        if (distance <= STOP_DISTANCE) break;

        args->moveFunction(fusionData);
        vTaskDelay(1000.0 / HZ - (millis() - msStart));
      }

      args->task->stop();
      delete args;
    }

    // Follow path
    struct FollowPathArgs : TaskArgs {
      PursuitData* data;
      PositionMember positionMember;
      NavigationTarget* navigationTarget;
      MoveFunction moveFunction;
    };

    static void followPathTask(void* task) {
      FollowPathArgs* args = (FollowPathArgs*)task;
      PursuitData* data = args->data;

      // Set first point
      SensorData sensorData = dataProvider->getData();
      FusionData fusionData = Fusion::getData(sensorData);
      args->navigationTarget->setDecelerationDistance(data->lookaheadDistance);

      data->lineIndex = 0;
      data->points.insert(data->points.begin(), fusionData.*(args->positionMember));

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);
        Vector3 position = fusionData.*(args->positionMember);

        Vector3 lookaheadPoint = Pursuit::findLookahead(position, data);
        args->navigationTarget->setTarget(lookaheadPoint);

        double distance = Navigation::getDistance(position, lookaheadPoint);
        if (distance <= STOP_DISTANCE) break;

        args->moveFunction(fusionData);
        vTaskDelay(1000.0 / HZ - (millis() - msStart));
      }

      data->points.clear();
      args->task->stop();
      delete args;
    }

    // Move functions
    static void moveRobot(FusionData fusionData) {
      NavigationData navigationData = Navigation::getData(fusionData);
      hardwareProvider->move(navigationData);
    }

    static void moveToolhead(FusionData fusionData) {
      ToolheadData toolheadData = Navigation::getToolheadData(fusionData);
      hardwareProvider->moveToolhead(toolheadData);
    }
};
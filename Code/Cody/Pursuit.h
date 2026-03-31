#pragma once
#include "IDataProvider.h"
#include "IHardwareProvider.h"
#include "SensorData.h"
#include "FusionData.h"
#include "NavigationData.h"
#include "Fusion.h"
#include "Navigation.h"
#include "Line.h"
#include "Task.h"
#include "TaskArgs.h"
#include <cmath>
#include <vector>

// Pursuit parameters
#define HZ 60.0

class Pursuit {
  public:
    static void initialize(IDataProvider& dataProvider_, IHardwareProvider& hardwareProvider_) {
      dataProvider = &dataProvider_;
      hardwareProvider = &hardwareProvider_;
    }

    static void addPoint(double x, double y) {
      Vector3 point = Vector3(x, y);
      points.push_back(point);
    }

    static Task* goToAsync(Vector3 target) {
      Task* task = new Task("goTo", goToTask);
      GoToArgs* args = new GoToArgs();

      args->task = task;
      args->target = target;

      task->start(args);
      return task;
    }

    static Task* followPathAsync(double lookaheadDistance) {
      Task* task = new Task("followPath", followPathTask);
      FollowPathArgs* args = new FollowPathArgs();

      args->task = task;
      args->lookaheadDistance = lookaheadDistance;

      task->start(args);
      return task;
    }

    static Task* moveToolheadAsync(double xPosition, double zPosition) {
      Task* task = new Task("moveToolhead", moveToolheadTask);
      MoveToolheadArgs* args = new MoveToolheadArgs();

      args->task = task;
      args->xPosition = xPosition;
      args->zPosition = zPosition;

      task->start(args);
      return task;
    }

  private:
    static IDataProvider* dataProvider;
    static IHardwareProvider* hardwareProvider;
    static std::vector<Vector3> points;
    static int lineIndex;

    struct GoToArgs : TaskArgs {
      Vector3 target;
    };

    static void goToTask(void* task) {
      GoToArgs* args = (GoToArgs*)task;
      Vector3 target = args->target;

      Navigation::setTarget(target);

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);

        double distance = Navigation::getDistance(fusionData.position, target);
        if (distance <= STOP_DISTANCE) break;

        NavigationData navigationData = Navigation::getData(fusionData);
        hardwareProvider->move(navigationData);

        vTaskDelay(1000.0 / HZ - (millis() - msStart));
      }

      args->task->stop();
      delete args;
    }

    struct FollowPathArgs : TaskArgs {
      double lookaheadDistance;
    };

    static void followPathTask(void* task) {
      FollowPathArgs* args = (FollowPathArgs*)task;
      double lookaheadDistance = args->lookaheadDistance;

      // Set first point
      SensorData sensorData = dataProvider->getData();
      FusionData fusionData = Fusion::getData(sensorData);
      Navigation::setDecelerationDistance(lookaheadDistance);

      lineIndex = 0;
      points.insert(points.begin(), fusionData.position);

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);
        Vector3 lookaheadPoint = findLookahead(fusionData.position, lookaheadDistance);
        Navigation::setTarget(lookaheadPoint);

        double distance = Navigation::getDistance(fusionData.position, lookaheadPoint);
        if (distance <= STOP_DISTANCE) break;

        NavigationData navigationData = Navigation::getData(fusionData);
        hardwareProvider->move(navigationData);

        vTaskDelay(1000.0 / HZ - (millis() - msStart));
      }

      args->task->stop();
      delete args;
    }

    static Vector3 findLookahead(Vector3 position, double lookaheadDistance) {
      std::vector<Line> lines;
      std::vector<double> lookaheadTimes;
      
      // Get points
      for (int i = 1; i < points.size(); i++) lines.push_back(Line(points[i - 1], points[i]));
      for (Line line : lines) lookaheadTimes.push_back(findLookaheadTime(position, line, lookaheadDistance));

      for (int i = lookaheadTimes.size() - 1; i >= 0; i--) {
        if (i != lineIndex && i != lineIndex + 1) continue;

        double t = lookaheadTimes[i];
        if (t < 0) continue;

        // Get point from time
        Line line = lines[i];
        double x = line.start.x + (line.end.x - line.start.x) * t;
        double y = line.start.y + (line.end.y - line.start.y) * t;

        lineIndex = i;
        return Vector3(x, y);
      }

      return lines[0].start;
    }

    static double findLookaheadTime(Vector3 position, Line line, double lookaheadDistance) {
      // Get vectors
      double dx = line.end.x - line.start.x;
      double dy = line.end.y - line.start.y;
      double fx = line.start.x - position.x;
      double fy = line.start.y - position.y;

      // Quadratic coefficients
      double r = lookaheadDistance;
      double a = dx * dx + dy * dy;
      double b = 2 * (fx * dx + fy * dy);
      double c = (fx * fx + fy * fy) - r * r;
      double d = b * b - 4 * a * c;

      if (d < 0) return -1;
      double t1 = std::clamp((-b + sqrt(d)) / (2 * a), 0.0, 1.0);
      double t2 = std::clamp((-b - sqrt(d)) / (2 * a), 0.0, 1.0);

      return max(t1, t2);
    }

    struct MoveToolheadArgs : TaskArgs {
      double xPosition;
      double zPosition;
    };

    static void moveToolheadTask(void* task) {
      MoveToolheadArgs* args = (MoveToolheadArgs*)task;
      
      Vector3 target = Vector3(args->xPosition, 0, args->zPosition);
      Navigation::setToolheadTarget(target);

      while (true) {
        unsigned long msStart = millis();

        SensorData sensorData = dataProvider->getData();
        FusionData fusionData = Fusion::getData(sensorData);

        ToolheadData toolheadData = Navigation::getToolheadData(fusionData);
        hardwareProvider->moveToolhead(toolheadData);

        if (abs(fusionData.toolheadPosition.x - target.x) <= TOOLHEAD_STOP_DISTANCE &&
            abs(fusionData.toolheadPosition.z - target.z) <= TOOLHEAD_STOP_DISTANCE) break;
        
        vTaskDelay(1000.0 / HZ - (millis() - msStart));
      }

      args->task->stop();
      delete args;
    }
};
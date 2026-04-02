#pragma once
#include "Line.h"
#include "PursuitData.h"
#include <cmath>
#include <vector>

class Pursuit {
  public:
    static Vector3 findLookahead(Vector3 position, PursuitData* data) {
      std::vector<Line> lines;
      std::vector<double> lookaheadTimes;
      
      // Get lookahead points
      for (int i = 1; i < data->points.size(); i++) 
        lines.push_back(Line(data->points[i - 1], data->points[i]));

      for (Line line : lines)
        lookaheadTimes.push_back(findLookaheadTime(position, line, data->lookaheadDistance));

      // Find next lookahead point
      for (int i = lookaheadTimes.size() - 1; i >= 0; i--) {
        if (i != data->lineIndex && i != data->lineIndex + 1) continue;

        double t = lookaheadTimes[i];
        if (t < 0) continue;

        // Get point from time
        Line line = lines[i];
        double x = line.start.x + (line.end.x - line.start.x) * t;
        double y = line.start.y + (line.end.y - line.start.y) * t;

        data->lineIndex = i;
        return Vector3(x, y);
      }

      return lines[0].start;
    }

    static double findLookaheadTime(Vector3 position, Line line, double r) {
      // Get vectors
      double dx = line.end.x - line.start.x;
      double dy = line.end.y - line.start.y;
      double fx = line.start.x - position.x;
      double fy = line.start.y - position.y;

      // Quadratic coefficients
      double a = dx * dx + dy * dy;
      double b = 2 * (fx * dx + fy * dy);
      double c = (fx * fx + fy * fy) - r * r;
      double d = b * b - 4 * a * c;

      if (d < 0) return -1;
      double t1 = std::clamp((-b + sqrt(d)) / (2 * a), 0.0, 1.0);
      double t2 = std::clamp((-b - sqrt(d)) / (2 * a), 0.0, 1.0);

      return max(t1, t2);
    }
};
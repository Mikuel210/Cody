#pragma once
#include "Navigation.h"

Vector3 Navigation::target;
Vector3 Navigation::toolheadTarget;
double Navigation::decelerationDistance = 100.0;

PID Navigation::orientationPid = PID(1, 0, 0);
PID Navigation::distancePid = PID(1, 0, 0);
PID Navigation::xAxisPid = PID(1, 0, 0);
PID Navigation::zAxisPid = PID(1, 0, 0);
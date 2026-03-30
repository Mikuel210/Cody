#pragma once
#include "Navigation.h"

PID Navigation::orientationPid = PID(1, 0, 0);
PID Navigation::distancePid = PID(1, 0, 0);
Vector3 Navigation::target;
double Navigation::decelerationDistance = 100.0;
#pragma once
#include "Navigation.h"

NavigationTarget Navigation::drive = NavigationTarget();
NavigationTarget Navigation::toolhead = NavigationTarget();

PID Navigation::orientationPid = PID(1, 0, 0);
PID Navigation::distancePid = PID(1, 0, 0);
PID Navigation::xAxisPid = PID(1, 0, 0);
PID Navigation::zAxisPid = PID(1, 0, 0);
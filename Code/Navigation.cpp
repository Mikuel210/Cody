#pragma once
#include "Navigation.h"

NavigationTarget Navigation::drive = NavigationTarget();
NavigationTarget Navigation::toolhead = NavigationTarget();
NavigationTarget Navigation::wheels = NavigationTarget();
NavigationTarget Navigation::mill = NavigationTarget();

PID Navigation::orientationPid = PID(1, 0, 0);
PID Navigation::distancePid = PID(1, 0, 0);
PID Navigation::xAxisPid = PID(1, 0, 0);
PID Navigation::zAxisPid = PID(1, 0, 0);
PID Navigation::wheelsPid = PID(1, 0, 0);
PID Navigation::millPid = PID(1, 0, 0);

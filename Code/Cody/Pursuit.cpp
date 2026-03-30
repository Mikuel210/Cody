#pragma once
#include "Pursuit.h"

IDataProvider* Pursuit::dataProvider = nullptr;
IHardwareProvider* Pursuit::hardwareProvider = nullptr;
std::vector<Vector3> Pursuit::points;
int Pursuit::lineIndex = 0;
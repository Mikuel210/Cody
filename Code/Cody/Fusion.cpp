#pragma once
#include "Fusion.h"

float Fusion::deltat;
SF Fusion::fusion;
Vector3 Fusion::previousPosition;
Vector3 Fusion::previousToolheadPosition;
double Fusion::previousOrientation;

int Fusion::previousLeftPulses;
int Fusion::previousRightPulses;
int Fusion::previousXAxisPulses;
int Fusion::previousZAxisPulses;
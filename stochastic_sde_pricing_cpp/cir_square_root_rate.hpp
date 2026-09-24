#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double cir_drift(double k, double theta, double r) { return k * (theta - r); }

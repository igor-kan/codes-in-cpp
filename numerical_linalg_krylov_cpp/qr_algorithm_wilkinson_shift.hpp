#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double wilkinson_shift(double d, double sign, double b2) { return d + sign * std::sqrt(d*d + b2); }

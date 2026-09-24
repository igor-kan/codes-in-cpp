#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double green_free_1d(double k, double r) { return std::sin(k * r) / (2.0 * k); }

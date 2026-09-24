#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline std::pair<double, double> givens_c_s(double a, double b) { double r = std::hypot(a, b); return { a / r, -b / r }; }

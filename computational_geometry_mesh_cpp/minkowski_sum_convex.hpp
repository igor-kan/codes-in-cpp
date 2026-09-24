#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline std::pair<double, double> minkowski_add(double ax, double ay, double bx, double by) { return { ax + bx, ay + by }; }

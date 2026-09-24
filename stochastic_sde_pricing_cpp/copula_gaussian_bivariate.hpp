#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline std::pair<double, double> correlated_normals(double z1, double z2, double rho) { return { z1, rho * z1 + std::sqrt(1.0 - rho*rho) * z2 }; }

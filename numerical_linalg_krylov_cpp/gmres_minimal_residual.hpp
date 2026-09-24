#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double gmres_residual(double s_k, double r0) { return std::abs(s_k) * r0; }

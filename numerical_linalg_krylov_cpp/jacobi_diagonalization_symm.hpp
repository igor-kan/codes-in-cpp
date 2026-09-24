#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double jacobi_theta(double a_ii, double a_jj, double a_ij) { return 0.5 * std::atan2(2.0 * a_ij, a_jj - a_ii); }

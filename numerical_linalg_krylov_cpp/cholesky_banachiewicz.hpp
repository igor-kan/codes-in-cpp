#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double cholesky_diag(double a_ii, double sum_sq) { return std::sqrt(a_ii - sum_sq); }

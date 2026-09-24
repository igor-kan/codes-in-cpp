#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double heston_var_trunc(double v) { return std::max(v, 0.0); }

#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline std::pair<double, double> antithetic_pair(double z) { return { z, -z }; }

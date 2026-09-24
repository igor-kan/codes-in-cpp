#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double j0_bessel(double x) { return (std::abs(x) < 1e-8) ? 1.0 : std::sin(x) / x; }

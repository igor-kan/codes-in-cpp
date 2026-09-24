#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double milstein_correction(double sigma, double dt, double dW) { return 0.5 * sigma * sigma * (dW * dW - dt); }

#pragma once
#include <cmath>

inline double estimate_eigenphase(double theta_rad) {
    return std::fmod(theta_rad, 2.0 * M_PI) / (2.0 * M_PI);
}

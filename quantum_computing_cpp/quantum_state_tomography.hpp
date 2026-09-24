#pragma once
#include <vector>
#include <cmath>

inline std::vector<double> bloch_coordinates_from_expectations(double exp_x, double exp_y, double exp_z) {
    return { exp_x, exp_y, exp_z };
}

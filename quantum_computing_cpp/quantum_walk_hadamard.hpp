#pragma once
#include <vector>
#include <cmath>

inline std::pair<double, double> hadamard_coin_step(double left, double right) {
    double s = 1.0 / std::sqrt(2.0);
    return { s * (left + right), s * (left - right) };
}

#pragma once
#include <vector>
#include <cmath>

inline std::vector<double> hadamard_gate_1d(const std::vector<double>& psi) {
    double s = 1.0 / std::sqrt(2.0);
    return { s * (psi[0] + psi[1]), s * (psi[0] - psi[1]) };
}

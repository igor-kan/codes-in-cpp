#pragma once
#include <complex>
#include <vector>

inline bool verify_teleportation_norm(const std::vector<std::complex<double>>& psi) {
    double norm = 0.0;
    for (const auto& a : psi) norm += std::norm(a);
    return std::abs(norm - 1.0) < 1e-6;
}

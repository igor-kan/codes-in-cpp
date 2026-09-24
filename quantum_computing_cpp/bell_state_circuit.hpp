#pragma once
#include <complex>
#include <vector>
#include <cmath>

inline std::vector<std::complex<double>> generate_phi_plus() {
    double inv_sqrt2 = 1.0 / std::sqrt(2.0);
    return { inv_sqrt2, 0.0, 0.0, inv_sqrt2 };
}

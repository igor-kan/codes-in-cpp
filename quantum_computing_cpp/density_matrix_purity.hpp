#pragma once
#include <vector>
#include <complex>

inline double calculate_matrix_purity(const std::vector<std::vector<std::complex<double>>>& rho) {
    size_t n = rho.size();
    double purity = 0.0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            purity += (rho[i][j] * rho[j][i]).real();
        }
    }
    return purity;
}

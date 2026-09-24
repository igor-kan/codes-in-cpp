#pragma once
#include <complex>
#include <vector>
#include <cmath>

inline std::vector<std::complex<double>> qft_1d(const std::vector<std::complex<double>>& state) {
    size_t n = state.size();
    std::vector<std::complex<double>> out(n, 0.0);
    double inv_sqrt_n = 1.0 / std::sqrt(static_cast<double>(n));
    for (size_t j = 0; j < n; ++j) {
        for (size_t k = 0; k < n; ++k) {
            double angle = 2.0 * M_PI * j * k / n;
            out[j] += state[k] * std::polar(1.0, angle);
        }
        out[j] *= inv_sqrt_n;
    }
    return out;
}

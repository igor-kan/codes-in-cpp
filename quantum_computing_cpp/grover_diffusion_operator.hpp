#pragma once
#include <vector>
#include <numeric>

inline std::vector<double> apply_grover_diffusion(const std::vector<double>& amplitudes) {
    size_t n = amplitudes.size();
    double mean = std::accumulate(amplitudes.begin(), amplitudes.end(), 0.0) / n;
    std::vector<double> out(n);
    for (size_t i = 0; i < n; ++i) {
        out[i] = 2.0 * mean - amplitudes[i];
    }
    return out;
}

#pragma once
#include <complex>
#include <vector>

inline double pure_state_fidelity(const std::vector<std::complex<double>>& psi,
                                 const std::vector<std::complex<double>>& phi) {
    std::complex<double> overlap = 0.0;
    for (size_t i = 0; i < psi.size(); ++i) overlap += std::conj(psi[i]) * phi[i];
    return std::norm(overlap);
}

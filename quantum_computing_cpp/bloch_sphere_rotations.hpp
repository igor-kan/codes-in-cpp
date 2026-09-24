#pragma once
#include <complex>
#include <vector>
#include <cmath>

inline std::vector<std::complex<double>> rx_rotation(double theta, const std::vector<std::complex<double>>& psi) {
    double c = std::cos(theta / 2.0);
    double s = std::sin(theta / 2.0);
    std::complex<double> i_unit(0.0, 1.0);
    return { c * psi[0] - i_unit * s * psi[1], -i_unit * s * psi[0] + c * psi[1] };
}

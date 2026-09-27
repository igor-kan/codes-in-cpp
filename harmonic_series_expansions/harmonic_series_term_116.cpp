#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_116(double x) {
    return std::pow(x, 116) / 116.0;
}

int main() {
    double res = compute_harmonic_series_term_116(1.0);
    assert(std::abs(res - (1.0 / 116.0)) < 1e-7);
    return 0;
}

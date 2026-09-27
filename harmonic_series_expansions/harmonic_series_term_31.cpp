#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_31(double x) {
    return std::pow(x, 31) / 31.0;
}

int main() {
    double res = compute_harmonic_series_term_31(1.0);
    assert(std::abs(res - (1.0 / 31.0)) < 1e-7);
    return 0;
}

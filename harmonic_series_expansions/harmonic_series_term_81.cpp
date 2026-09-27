#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_81(double x) {
    return std::pow(x, 81) / 81.0;
}

int main() {
    double res = compute_harmonic_series_term_81(1.0);
    assert(std::abs(res - (1.0 / 81.0)) < 1e-7);
    return 0;
}

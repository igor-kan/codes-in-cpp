#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_36(double x) {
    return std::pow(x, 36) / 36.0;
}

int main() {
    double res = compute_harmonic_series_term_36(1.0);
    assert(std::abs(res - (1.0 / 36.0)) < 1e-7);
    return 0;
}

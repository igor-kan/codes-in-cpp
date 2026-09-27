#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_56(double x) {
    return std::pow(x, 56) / 56.0;
}

int main() {
    double res = compute_harmonic_series_term_56(1.0);
    assert(std::abs(res - (1.0 / 56.0)) < 1e-7);
    return 0;
}

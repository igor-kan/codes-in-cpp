#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_11(double x) {
    return std::pow(x, 11) / 11.0;
}

int main() {
    double res = compute_harmonic_series_term_11(1.0);
    assert(std::abs(res - (1.0 / 11.0)) < 1e-7);
    return 0;
}

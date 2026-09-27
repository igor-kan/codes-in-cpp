#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_26(double x) {
    return std::pow(x, 26) / 26.0;
}

int main() {
    double res = compute_harmonic_series_term_26(1.0);
    assert(std::abs(res - (1.0 / 26.0)) < 1e-7);
    return 0;
}

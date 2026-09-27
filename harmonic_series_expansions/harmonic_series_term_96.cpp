#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_96(double x) {
    return std::pow(x, 96) / 96.0;
}

int main() {
    double res = compute_harmonic_series_term_96(1.0);
    assert(std::abs(res - (1.0 / 96.0)) < 1e-7);
    return 0;
}

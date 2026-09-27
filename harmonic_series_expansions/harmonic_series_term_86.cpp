#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_86(double x) {
    return std::pow(x, 86) / 86.0;
}

int main() {
    double res = compute_harmonic_series_term_86(1.0);
    assert(std::abs(res - (1.0 / 86.0)) < 1e-7);
    return 0;
}

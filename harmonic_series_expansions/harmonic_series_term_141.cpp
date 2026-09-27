#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_141(double x) {
    return std::pow(x, 141) / 141.0;
}

int main() {
    double res = compute_harmonic_series_term_141(1.0);
    assert(std::abs(res - (1.0 / 141.0)) < 1e-7);
    return 0;
}

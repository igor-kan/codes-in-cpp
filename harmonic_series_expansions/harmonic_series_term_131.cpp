#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_131(double x) {
    return std::pow(x, 131) / 131.0;
}

int main() {
    double res = compute_harmonic_series_term_131(1.0);
    assert(std::abs(res - (1.0 / 131.0)) < 1e-7);
    return 0;
}

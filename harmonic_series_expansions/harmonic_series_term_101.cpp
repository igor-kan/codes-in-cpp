#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_101(double x) {
    return std::pow(x, 101) / 101.0;
}

int main() {
    double res = compute_harmonic_series_term_101(1.0);
    assert(std::abs(res - (1.0 / 101.0)) < 1e-7);
    return 0;
}

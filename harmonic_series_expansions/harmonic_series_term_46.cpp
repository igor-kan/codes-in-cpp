#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_46(double x) {
    return std::pow(x, 46) / 46.0;
}

int main() {
    double res = compute_harmonic_series_term_46(1.0);
    assert(std::abs(res - (1.0 / 46.0)) < 1e-7);
    return 0;
}

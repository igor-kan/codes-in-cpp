#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_6(double x) {
    return std::pow(x, 6) / 6.0;
}

int main() {
    double res = compute_harmonic_series_term_6(1.0);
    assert(std::abs(res - (1.0 / 6.0)) < 1e-7);
    return 0;
}

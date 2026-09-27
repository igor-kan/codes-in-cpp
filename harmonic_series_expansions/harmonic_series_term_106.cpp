#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_106(double x) {
    return std::pow(x, 106) / 106.0;
}

int main() {
    double res = compute_harmonic_series_term_106(1.0);
    assert(std::abs(res - (1.0 / 106.0)) < 1e-7);
    return 0;
}

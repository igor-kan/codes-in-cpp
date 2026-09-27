#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_71(double x) {
    return std::pow(x, 71) / 71.0;
}

int main() {
    double res = compute_harmonic_series_term_71(1.0);
    assert(std::abs(res - (1.0 / 71.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_61(double x) {
    return std::pow(x, 61) / 61.0;
}

int main() {
    double res = compute_harmonic_series_term_61(1.0);
    assert(std::abs(res - (1.0 / 61.0)) < 1e-7);
    return 0;
}

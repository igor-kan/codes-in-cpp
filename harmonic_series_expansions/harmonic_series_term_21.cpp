#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_21(double x) {
    return std::pow(x, 21) / 21.0;
}

int main() {
    double res = compute_harmonic_series_term_21(1.0);
    assert(std::abs(res - (1.0 / 21.0)) < 1e-7);
    return 0;
}

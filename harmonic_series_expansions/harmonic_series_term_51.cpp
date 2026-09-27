#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_51(double x) {
    return std::pow(x, 51) / 51.0;
}

int main() {
    double res = compute_harmonic_series_term_51(1.0);
    assert(std::abs(res - (1.0 / 51.0)) < 1e-7);
    return 0;
}

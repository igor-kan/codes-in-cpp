#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_76(double x) {
    return std::pow(x, 76) / 76.0;
}

int main() {
    double res = compute_harmonic_series_term_76(1.0);
    assert(std::abs(res - (1.0 / 76.0)) < 1e-7);
    return 0;
}

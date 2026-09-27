#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_126(double x) {
    return std::pow(x, 126) / 126.0;
}

int main() {
    double res = compute_harmonic_series_term_126(1.0);
    assert(std::abs(res - (1.0 / 126.0)) < 1e-7);
    return 0;
}

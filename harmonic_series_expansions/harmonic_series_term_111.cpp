#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_111(double x) {
    return std::pow(x, 111) / 111.0;
}

int main() {
    double res = compute_harmonic_series_term_111(1.0);
    assert(std::abs(res - (1.0 / 111.0)) < 1e-7);
    return 0;
}

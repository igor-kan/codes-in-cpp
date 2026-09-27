#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_91(double x) {
    return std::pow(x, 91) / 91.0;
}

int main() {
    double res = compute_harmonic_series_term_91(1.0);
    assert(std::abs(res - (1.0 / 91.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_66(double x) {
    return std::pow(x, 66) / 66.0;
}

int main() {
    double res = compute_harmonic_series_term_66(1.0);
    assert(std::abs(res - (1.0 / 66.0)) < 1e-7);
    return 0;
}

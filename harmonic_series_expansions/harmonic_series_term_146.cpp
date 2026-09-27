#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_146(double x) {
    return std::pow(x, 146) / 146.0;
}

int main() {
    double res = compute_harmonic_series_term_146(1.0);
    assert(std::abs(res - (1.0 / 146.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_136(double x) {
    return std::pow(x, 136) / 136.0;
}

int main() {
    double res = compute_harmonic_series_term_136(1.0);
    assert(std::abs(res - (1.0 / 136.0)) < 1e-7);
    return 0;
}

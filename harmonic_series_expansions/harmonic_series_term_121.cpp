#include <iostream>
#include <cmath>
#include <cassert>

double compute_harmonic_series_term_121(double x) {
    return std::pow(x, 121) / 121.0;
}

int main() {
    double res = compute_harmonic_series_term_121(1.0);
    assert(std::abs(res - (1.0 / 121.0)) < 1e-7);
    return 0;
}

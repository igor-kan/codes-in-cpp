#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_140(double x) {
    return std::pow(x, 140) / 140.0;
}

int main() {
    double res = compute_power_series_term_140(1.0);
    assert(std::abs(res - (1.0 / 140.0)) < 1e-7);
    return 0;
}

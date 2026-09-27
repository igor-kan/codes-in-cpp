#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_125(double x) {
    return std::pow(x, 125) / 125.0;
}

int main() {
    double res = compute_power_series_term_125(1.0);
    assert(std::abs(res - (1.0 / 125.0)) < 1e-7);
    return 0;
}

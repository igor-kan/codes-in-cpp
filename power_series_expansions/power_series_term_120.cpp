#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_120(double x) {
    return std::pow(x, 120) / 120.0;
}

int main() {
    double res = compute_power_series_term_120(1.0);
    assert(std::abs(res - (1.0 / 120.0)) < 1e-7);
    return 0;
}

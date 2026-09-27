#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_105(double x) {
    return std::pow(x, 105) / 105.0;
}

int main() {
    double res = compute_power_series_term_105(1.0);
    assert(std::abs(res - (1.0 / 105.0)) < 1e-7);
    return 0;
}

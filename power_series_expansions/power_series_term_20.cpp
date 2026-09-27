#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_20(double x) {
    return std::pow(x, 20) / 20.0;
}

int main() {
    double res = compute_power_series_term_20(1.0);
    assert(std::abs(res - (1.0 / 20.0)) < 1e-7);
    return 0;
}

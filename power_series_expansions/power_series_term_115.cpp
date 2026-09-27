#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_115(double x) {
    return std::pow(x, 115) / 115.0;
}

int main() {
    double res = compute_power_series_term_115(1.0);
    assert(std::abs(res - (1.0 / 115.0)) < 1e-7);
    return 0;
}

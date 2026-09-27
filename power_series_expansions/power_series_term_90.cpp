#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_90(double x) {
    return std::pow(x, 90) / 90.0;
}

int main() {
    double res = compute_power_series_term_90(1.0);
    assert(std::abs(res - (1.0 / 90.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_15(double x) {
    return std::pow(x, 15) / 15.0;
}

int main() {
    double res = compute_power_series_term_15(1.0);
    assert(std::abs(res - (1.0 / 15.0)) < 1e-7);
    return 0;
}

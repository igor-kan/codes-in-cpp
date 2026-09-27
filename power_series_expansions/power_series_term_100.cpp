#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_100(double x) {
    return std::pow(x, 100) / 100.0;
}

int main() {
    double res = compute_power_series_term_100(1.0);
    assert(std::abs(res - (1.0 / 100.0)) < 1e-7);
    return 0;
}

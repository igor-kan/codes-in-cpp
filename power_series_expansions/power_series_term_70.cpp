#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_70(double x) {
    return std::pow(x, 70) / 70.0;
}

int main() {
    double res = compute_power_series_term_70(1.0);
    assert(std::abs(res - (1.0 / 70.0)) < 1e-7);
    return 0;
}

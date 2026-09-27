#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_30(double x) {
    return std::pow(x, 30) / 30.0;
}

int main() {
    double res = compute_power_series_term_30(1.0);
    assert(std::abs(res - (1.0 / 30.0)) < 1e-7);
    return 0;
}

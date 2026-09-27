#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_110(double x) {
    return std::pow(x, 110) / 110.0;
}

int main() {
    double res = compute_power_series_term_110(1.0);
    assert(std::abs(res - (1.0 / 110.0)) < 1e-7);
    return 0;
}

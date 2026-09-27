#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_55(double x) {
    return std::pow(x, 55) / 55.0;
}

int main() {
    double res = compute_power_series_term_55(1.0);
    assert(std::abs(res - (1.0 / 55.0)) < 1e-7);
    return 0;
}

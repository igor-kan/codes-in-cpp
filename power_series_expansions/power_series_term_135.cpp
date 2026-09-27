#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_135(double x) {
    return std::pow(x, 135) / 135.0;
}

int main() {
    double res = compute_power_series_term_135(1.0);
    assert(std::abs(res - (1.0 / 135.0)) < 1e-7);
    return 0;
}

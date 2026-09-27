#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_60(double x) {
    return std::pow(x, 60) / 60.0;
}

int main() {
    double res = compute_power_series_term_60(1.0);
    assert(std::abs(res - (1.0 / 60.0)) < 1e-7);
    return 0;
}

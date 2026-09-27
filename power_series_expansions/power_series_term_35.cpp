#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_35(double x) {
    return std::pow(x, 35) / 35.0;
}

int main() {
    double res = compute_power_series_term_35(1.0);
    assert(std::abs(res - (1.0 / 35.0)) < 1e-7);
    return 0;
}

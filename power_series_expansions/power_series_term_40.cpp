#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_40(double x) {
    return std::pow(x, 40) / 40.0;
}

int main() {
    double res = compute_power_series_term_40(1.0);
    assert(std::abs(res - (1.0 / 40.0)) < 1e-7);
    return 0;
}

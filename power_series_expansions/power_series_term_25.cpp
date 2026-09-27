#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_25(double x) {
    return std::pow(x, 25) / 25.0;
}

int main() {
    double res = compute_power_series_term_25(1.0);
    assert(std::abs(res - (1.0 / 25.0)) < 1e-7);
    return 0;
}

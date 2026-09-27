#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_80(double x) {
    return std::pow(x, 80) / 80.0;
}

int main() {
    double res = compute_power_series_term_80(1.0);
    assert(std::abs(res - (1.0 / 80.0)) < 1e-7);
    return 0;
}

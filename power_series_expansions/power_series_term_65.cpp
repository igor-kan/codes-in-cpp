#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_65(double x) {
    return std::pow(x, 65) / 65.0;
}

int main() {
    double res = compute_power_series_term_65(1.0);
    assert(std::abs(res - (1.0 / 65.0)) < 1e-7);
    return 0;
}

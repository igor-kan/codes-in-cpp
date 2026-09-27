#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_50(double x) {
    return std::pow(x, 50) / 50.0;
}

int main() {
    double res = compute_power_series_term_50(1.0);
    assert(std::abs(res - (1.0 / 50.0)) < 1e-7);
    return 0;
}

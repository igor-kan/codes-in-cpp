#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_45(double x) {
    return std::pow(x, 45) / 45.0;
}

int main() {
    double res = compute_power_series_term_45(1.0);
    assert(std::abs(res - (1.0 / 45.0)) < 1e-7);
    return 0;
}

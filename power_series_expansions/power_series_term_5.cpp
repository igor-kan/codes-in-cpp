#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_5(double x) {
    return std::pow(x, 5) / 5.0;
}

int main() {
    double res = compute_power_series_term_5(1.0);
    assert(std::abs(res - (1.0 / 5.0)) < 1e-7);
    return 0;
}

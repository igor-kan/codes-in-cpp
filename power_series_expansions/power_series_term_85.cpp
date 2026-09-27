#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_85(double x) {
    return std::pow(x, 85) / 85.0;
}

int main() {
    double res = compute_power_series_term_85(1.0);
    assert(std::abs(res - (1.0 / 85.0)) < 1e-7);
    return 0;
}

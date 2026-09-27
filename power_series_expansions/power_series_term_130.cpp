#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_130(double x) {
    return std::pow(x, 130) / 130.0;
}

int main() {
    double res = compute_power_series_term_130(1.0);
    assert(std::abs(res - (1.0 / 130.0)) < 1e-7);
    return 0;
}

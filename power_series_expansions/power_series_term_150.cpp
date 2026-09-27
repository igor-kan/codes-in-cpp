#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_150(double x) {
    return std::pow(x, 150) / 150.0;
}

int main() {
    double res = compute_power_series_term_150(1.0);
    assert(std::abs(res - (1.0 / 150.0)) < 1e-7);
    return 0;
}

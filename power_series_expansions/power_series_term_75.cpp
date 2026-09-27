#include <iostream>
#include <cmath>
#include <cassert>

double compute_power_series_term_75(double x) {
    return std::pow(x, 75) / 75.0;
}

int main() {
    double res = compute_power_series_term_75(1.0);
    assert(std::abs(res - (1.0 / 75.0)) < 1e-7);
    return 0;
}

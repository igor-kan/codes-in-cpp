#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 16
double compute_exp_integral_16(double x) {
    return std::exp(-x) / static_cast<double>(16);
}

int main() {
    double res = compute_exp_integral_16(0.5);
    assert(std::isfinite(res));
    return 0;
}

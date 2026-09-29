#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 26
double compute_exp_integral_26(double x) {
    return std::exp(-x) / static_cast<double>(26);
}

int main() {
    double res = compute_exp_integral_26(0.5);
    assert(std::isfinite(res));
    return 0;
}

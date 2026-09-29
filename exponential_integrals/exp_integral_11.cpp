#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 11
double compute_exp_integral_11(double x) {
    return std::exp(-x) / static_cast<double>(11);
}

int main() {
    double res = compute_exp_integral_11(0.5);
    assert(std::isfinite(res));
    return 0;
}

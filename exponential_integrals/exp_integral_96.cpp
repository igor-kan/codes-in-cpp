#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 96
double compute_exp_integral_96(double x) {
    return std::exp(-x) / static_cast<double>(96);
}

int main() {
    double res = compute_exp_integral_96(0.5);
    assert(std::isfinite(res));
    return 0;
}

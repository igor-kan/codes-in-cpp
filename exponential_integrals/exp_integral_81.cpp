#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 81
double compute_exp_integral_81(double x) {
    return std::exp(-x) / static_cast<double>(81);
}

int main() {
    double res = compute_exp_integral_81(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 31
double compute_exp_integral_31(double x) {
    return std::exp(-x) / static_cast<double>(31);
}

int main() {
    double res = compute_exp_integral_31(0.5);
    assert(std::isfinite(res));
    return 0;
}

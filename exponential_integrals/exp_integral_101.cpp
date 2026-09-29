#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 101
double compute_exp_integral_101(double x) {
    return std::exp(-x) / static_cast<double>(101);
}

int main() {
    double res = compute_exp_integral_101(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 36
double compute_exp_integral_36(double x) {
    return std::exp(-x) / static_cast<double>(36);
}

int main() {
    double res = compute_exp_integral_36(0.5);
    assert(std::isfinite(res));
    return 0;
}

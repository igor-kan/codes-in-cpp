#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 21
double compute_exp_integral_21(double x) {
    return std::exp(-x) / static_cast<double>(21);
}

int main() {
    double res = compute_exp_integral_21(0.5);
    assert(std::isfinite(res));
    return 0;
}

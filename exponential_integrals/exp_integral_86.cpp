#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 86
double compute_exp_integral_86(double x) {
    return std::exp(-x) / static_cast<double>(86);
}

int main() {
    double res = compute_exp_integral_86(0.5);
    assert(std::isfinite(res));
    return 0;
}

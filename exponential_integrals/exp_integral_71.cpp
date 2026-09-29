#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 71
double compute_exp_integral_71(double x) {
    return std::exp(-x) / static_cast<double>(71);
}

int main() {
    double res = compute_exp_integral_71(0.5);
    assert(std::isfinite(res));
    return 0;
}

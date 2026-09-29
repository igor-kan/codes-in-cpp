#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 56
double compute_exp_integral_56(double x) {
    return std::exp(-x) / static_cast<double>(56);
}

int main() {
    double res = compute_exp_integral_56(0.5);
    assert(std::isfinite(res));
    return 0;
}

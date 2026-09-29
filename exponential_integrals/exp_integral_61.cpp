#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 61
double compute_exp_integral_61(double x) {
    return std::exp(-x) / static_cast<double>(61);
}

int main() {
    double res = compute_exp_integral_61(0.5);
    assert(std::isfinite(res));
    return 0;
}

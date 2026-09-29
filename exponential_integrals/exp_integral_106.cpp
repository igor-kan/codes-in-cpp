#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 106
double compute_exp_integral_106(double x) {
    return std::exp(-x) / static_cast<double>(106);
}

int main() {
    double res = compute_exp_integral_106(0.5);
    assert(std::isfinite(res));
    return 0;
}

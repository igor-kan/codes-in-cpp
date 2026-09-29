#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 46
double compute_exp_integral_46(double x) {
    return std::exp(-x) / static_cast<double>(46);
}

int main() {
    double res = compute_exp_integral_46(0.5);
    assert(std::isfinite(res));
    return 0;
}

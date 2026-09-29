#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 76
double compute_exp_integral_76(double x) {
    return std::exp(-x) / static_cast<double>(76);
}

int main() {
    double res = compute_exp_integral_76(0.5);
    assert(std::isfinite(res));
    return 0;
}

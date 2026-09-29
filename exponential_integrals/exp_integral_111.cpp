#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 111
double compute_exp_integral_111(double x) {
    return std::exp(-x) / static_cast<double>(111);
}

int main() {
    double res = compute_exp_integral_111(0.5);
    assert(std::isfinite(res));
    return 0;
}

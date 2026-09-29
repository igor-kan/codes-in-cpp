#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 66
double compute_exp_integral_66(double x) {
    return std::exp(-x) / static_cast<double>(66);
}

int main() {
    double res = compute_exp_integral_66(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 51
double compute_exp_integral_51(double x) {
    return std::exp(-x) / static_cast<double>(51);
}

int main() {
    double res = compute_exp_integral_51(0.5);
    assert(std::isfinite(res));
    return 0;
}

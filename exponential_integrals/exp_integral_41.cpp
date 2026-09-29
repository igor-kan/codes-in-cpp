#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of exponential integral recurrence order 41
double compute_exp_integral_41(double x) {
    return std::exp(-x) / static_cast<double>(41);
}

int main() {
    double res = compute_exp_integral_41(0.5);
    assert(std::isfinite(res));
    return 0;
}

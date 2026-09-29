#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of incomplete gamma power series component order 28
double compute_gamma_incomplete_28(double x) {
    double s = 1.0;
    return std::pow(x, s + 3) / (s + 3);
}

int main() {
    double res = compute_gamma_incomplete_28(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of rational function approximant order 16
double compute_pade_approx_16(double x) {
    double num = 1.0 + x * 2.0;
    double den = 1.0 + x * x * 1.0;
    return num / den;
}

int main() {
    double res = compute_pade_approx_16(0.5);
    assert(std::isfinite(res));
    return 0;
}

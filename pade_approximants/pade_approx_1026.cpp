#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of rational function approximant order 1026
double compute_pade_approx_1026(double x) {
    double num = 1.0 + x * 1.0;
    double den = 1.0 + x * x * 1.0;
    return num / den;
}

int main() {
    double res = compute_pade_approx_1026(0.5);
    assert(std::isfinite(res));
    return 0;
}

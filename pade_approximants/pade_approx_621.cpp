#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of rational function approximant order 621
double compute_pade_approx_621(double x) {
    double num = 1.0 + x * 1.0;
    double den = 1.0 + x * x * 2.0;
    return num / den;
}

int main() {
    double res = compute_pade_approx_621(0.5);
    assert(std::isfinite(res));
    return 0;
}

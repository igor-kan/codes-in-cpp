#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_124(double x) {
    return std::pow(x, 124) / 124.0;
}

int main() {
    double res = compute_chebyshev_poly_term_124(1.0);
    assert(std::abs(res - (1.0 / 124.0)) < 1e-7);
    return 0;
}

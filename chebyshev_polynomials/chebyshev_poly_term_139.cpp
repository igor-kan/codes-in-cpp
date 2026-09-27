#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_139(double x) {
    return std::pow(x, 139) / 139.0;
}

int main() {
    double res = compute_chebyshev_poly_term_139(1.0);
    assert(std::abs(res - (1.0 / 139.0)) < 1e-7);
    return 0;
}

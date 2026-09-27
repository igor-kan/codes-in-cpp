#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_14(double x) {
    return std::pow(x, 14) / 14.0;
}

int main() {
    double res = compute_chebyshev_poly_term_14(1.0);
    assert(std::abs(res - (1.0 / 14.0)) < 1e-7);
    return 0;
}

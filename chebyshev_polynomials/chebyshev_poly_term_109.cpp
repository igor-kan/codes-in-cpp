#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_109(double x) {
    return std::pow(x, 109) / 109.0;
}

int main() {
    double res = compute_chebyshev_poly_term_109(1.0);
    assert(std::abs(res - (1.0 / 109.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_39(double x) {
    return std::pow(x, 39) / 39.0;
}

int main() {
    double res = compute_chebyshev_poly_term_39(1.0);
    assert(std::abs(res - (1.0 / 39.0)) < 1e-7);
    return 0;
}

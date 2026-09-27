#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_24(double x) {
    return std::pow(x, 24) / 24.0;
}

int main() {
    double res = compute_chebyshev_poly_term_24(1.0);
    assert(std::abs(res - (1.0 / 24.0)) < 1e-7);
    return 0;
}

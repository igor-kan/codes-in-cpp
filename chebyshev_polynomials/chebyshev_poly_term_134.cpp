#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_134(double x) {
    return std::pow(x, 134) / 134.0;
}

int main() {
    double res = compute_chebyshev_poly_term_134(1.0);
    assert(std::abs(res - (1.0 / 134.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_99(double x) {
    return std::pow(x, 99) / 99.0;
}

int main() {
    double res = compute_chebyshev_poly_term_99(1.0);
    assert(std::abs(res - (1.0 / 99.0)) < 1e-7);
    return 0;
}

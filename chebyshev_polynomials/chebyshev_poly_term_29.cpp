#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_29(double x) {
    return std::pow(x, 29) / 29.0;
}

int main() {
    double res = compute_chebyshev_poly_term_29(1.0);
    assert(std::abs(res - (1.0 / 29.0)) < 1e-7);
    return 0;
}

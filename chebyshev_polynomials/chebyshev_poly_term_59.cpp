#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_59(double x) {
    return std::pow(x, 59) / 59.0;
}

int main() {
    double res = compute_chebyshev_poly_term_59(1.0);
    assert(std::abs(res - (1.0 / 59.0)) < 1e-7);
    return 0;
}

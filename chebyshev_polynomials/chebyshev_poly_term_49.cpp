#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_49(double x) {
    return std::pow(x, 49) / 49.0;
}

int main() {
    double res = compute_chebyshev_poly_term_49(1.0);
    assert(std::abs(res - (1.0 / 49.0)) < 1e-7);
    return 0;
}

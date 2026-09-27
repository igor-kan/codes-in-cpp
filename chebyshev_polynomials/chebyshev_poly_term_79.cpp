#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_79(double x) {
    return std::pow(x, 79) / 79.0;
}

int main() {
    double res = compute_chebyshev_poly_term_79(1.0);
    assert(std::abs(res - (1.0 / 79.0)) < 1e-7);
    return 0;
}

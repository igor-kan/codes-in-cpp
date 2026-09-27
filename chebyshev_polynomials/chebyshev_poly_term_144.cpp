#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_144(double x) {
    return std::pow(x, 144) / 144.0;
}

int main() {
    double res = compute_chebyshev_poly_term_144(1.0);
    assert(std::abs(res - (1.0 / 144.0)) < 1e-7);
    return 0;
}

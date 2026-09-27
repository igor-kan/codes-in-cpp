#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_114(double x) {
    return std::pow(x, 114) / 114.0;
}

int main() {
    double res = compute_chebyshev_poly_term_114(1.0);
    assert(std::abs(res - (1.0 / 114.0)) < 1e-7);
    return 0;
}

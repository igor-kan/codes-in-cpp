#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_89(double x) {
    return std::pow(x, 89) / 89.0;
}

int main() {
    double res = compute_chebyshev_poly_term_89(1.0);
    assert(std::abs(res - (1.0 / 89.0)) < 1e-7);
    return 0;
}

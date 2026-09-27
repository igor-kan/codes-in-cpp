#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_69(double x) {
    return std::pow(x, 69) / 69.0;
}

int main() {
    double res = compute_chebyshev_poly_term_69(1.0);
    assert(std::abs(res - (1.0 / 69.0)) < 1e-7);
    return 0;
}

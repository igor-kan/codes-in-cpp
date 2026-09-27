#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_94(double x) {
    return std::pow(x, 94) / 94.0;
}

int main() {
    double res = compute_chebyshev_poly_term_94(1.0);
    assert(std::abs(res - (1.0 / 94.0)) < 1e-7);
    return 0;
}

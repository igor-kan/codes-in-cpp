#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_34(double x) {
    return std::pow(x, 34) / 34.0;
}

int main() {
    double res = compute_chebyshev_poly_term_34(1.0);
    assert(std::abs(res - (1.0 / 34.0)) < 1e-7);
    return 0;
}

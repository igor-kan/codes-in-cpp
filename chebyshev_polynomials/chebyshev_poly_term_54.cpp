#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_54(double x) {
    return std::pow(x, 54) / 54.0;
}

int main() {
    double res = compute_chebyshev_poly_term_54(1.0);
    assert(std::abs(res - (1.0 / 54.0)) < 1e-7);
    return 0;
}

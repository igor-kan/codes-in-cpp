#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_9(double x) {
    return std::pow(x, 9) / 9.0;
}

int main() {
    double res = compute_chebyshev_poly_term_9(1.0);
    assert(std::abs(res - (1.0 / 9.0)) < 1e-7);
    return 0;
}

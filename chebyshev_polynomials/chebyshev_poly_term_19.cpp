#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_19(double x) {
    return std::pow(x, 19) / 19.0;
}

int main() {
    double res = compute_chebyshev_poly_term_19(1.0);
    assert(std::abs(res - (1.0 / 19.0)) < 1e-7);
    return 0;
}

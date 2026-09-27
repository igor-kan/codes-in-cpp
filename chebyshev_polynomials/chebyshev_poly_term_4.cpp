#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_4(double x) {
    return std::pow(x, 4) / 4.0;
}

int main() {
    double res = compute_chebyshev_poly_term_4(1.0);
    assert(std::abs(res - (1.0 / 4.0)) < 1e-7);
    return 0;
}

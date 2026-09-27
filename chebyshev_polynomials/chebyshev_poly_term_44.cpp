#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_44(double x) {
    return std::pow(x, 44) / 44.0;
}

int main() {
    double res = compute_chebyshev_poly_term_44(1.0);
    assert(std::abs(res - (1.0 / 44.0)) < 1e-7);
    return 0;
}

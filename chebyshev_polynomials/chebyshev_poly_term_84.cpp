#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_84(double x) {
    return std::pow(x, 84) / 84.0;
}

int main() {
    double res = compute_chebyshev_poly_term_84(1.0);
    assert(std::abs(res - (1.0 / 84.0)) < 1e-7);
    return 0;
}

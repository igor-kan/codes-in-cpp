#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_104(double x) {
    return std::pow(x, 104) / 104.0;
}

int main() {
    double res = compute_chebyshev_poly_term_104(1.0);
    assert(std::abs(res - (1.0 / 104.0)) < 1e-7);
    return 0;
}

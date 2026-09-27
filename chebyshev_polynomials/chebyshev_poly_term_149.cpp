#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_149(double x) {
    return std::pow(x, 149) / 149.0;
}

int main() {
    double res = compute_chebyshev_poly_term_149(1.0);
    assert(std::abs(res - (1.0 / 149.0)) < 1e-7);
    return 0;
}

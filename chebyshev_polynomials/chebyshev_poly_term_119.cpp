#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_119(double x) {
    return std::pow(x, 119) / 119.0;
}

int main() {
    double res = compute_chebyshev_poly_term_119(1.0);
    assert(std::abs(res - (1.0 / 119.0)) < 1e-7);
    return 0;
}

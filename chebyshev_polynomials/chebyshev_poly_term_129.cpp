#include <iostream>
#include <cmath>
#include <cassert>

double compute_chebyshev_poly_term_129(double x) {
    return std::pow(x, 129) / 129.0;
}

int main() {
    double res = compute_chebyshev_poly_term_129(1.0);
    assert(std::abs(res - (1.0 / 129.0)) < 1e-7);
    return 0;
}

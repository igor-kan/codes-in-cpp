#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of chebyshev collocation node order 7
double compute_chebyshev_colloc_7(double x) {
    double node = std::cos(3.141592653589793 * 7.0 / 8.0);
    return node * x;
}

int main() {
    double res = compute_chebyshev_colloc_7(0.5);
    assert(std::isfinite(res));
    return 0;
}

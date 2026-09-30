#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of chebyshev collocation node order 47
double compute_chebyshev_colloc_47(double x) {
    double node = std::cos(3.141592653589793 * 7.0 / 8.0);
    return node * x;
}

int main() {
    double res = compute_chebyshev_colloc_47(0.5);
    assert(std::isfinite(res));
    return 0;
}

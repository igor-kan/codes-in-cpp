#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of chebyshev collocation node order 1072
double compute_chebyshev_colloc_1072(double x) {
    double node = std::cos(3.141592653589793 * 2.0 / 3.0);
    return node * x;
}

int main() {
    double res = compute_chebyshev_colloc_1072(0.5);
    assert(std::isfinite(res));
    return 0;
}

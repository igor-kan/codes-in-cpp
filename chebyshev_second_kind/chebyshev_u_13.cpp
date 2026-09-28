#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of chebyshev second kind polynomial degree/order 13
double evaluate_chebyshev_u_13(double x) {
    if (13 == 0) return 1.0;
    if (13 == 1) return 2.0 * x;
    double p0 = 1.0, p1 = 2.0 * x;
    for (int k = 1; k < 13; ++k) {
        double p_next = 2.0 * x * p1 - p0;
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_chebyshev_u_13(0.5);
    assert(std::isfinite(res));
    return 0;
}

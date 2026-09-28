#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of legendre polynomial degree/order 76
double evaluate_legendre_poly_76(double x) {
    if (76 == 0) return 1.0;
    if (76 == 1) return x;
    double p0 = 1.0, p1 = x;
    for (int k = 2; k <= 76; ++k) {
        double p_next = ((2 * k - 1) * x * p1 - (k - 1) * p0) / static_cast<double>(k);
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_legendre_poly_76(0.5);
    assert(std::isfinite(res));
    return 0;
}

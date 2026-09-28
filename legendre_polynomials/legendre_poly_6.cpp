#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of legendre polynomial degree/order 6
double evaluate_legendre_poly_6(double x) {
    if (6 == 0) return 1.0;
    if (6 == 1) return x;
    double p0 = 1.0, p1 = x;
    for (int k = 2; k <= 6; ++k) {
        double p_next = ((2 * k - 1) * x * p1 - (k - 1) * p0) / static_cast<double>(k);
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_legendre_poly_6(0.5);
    assert(std::isfinite(res));
    return 0;
}

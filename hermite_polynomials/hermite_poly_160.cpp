#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of hermite polynomial degree/order 160
double evaluate_hermite_poly_160(double x) {
    if (160 == 0) return 1.0;
    if (160 == 1) return 2.0 * x;
    double p0 = 1.0, p1 = 2.0 * x;
    for (int k = 1; k < 160; ++k) {
        double p_next = 2.0 * x * p1 - 2.0 * k * p0;
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_hermite_poly_160(0.5);
    assert(std::isfinite(res));
    return 0;
}

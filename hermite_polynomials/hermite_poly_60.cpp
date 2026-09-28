#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of hermite polynomial degree/order 60
double evaluate_hermite_poly_60(double x) {
    if (60 == 0) return 1.0;
    if (60 == 1) return 2.0 * x;
    double p0 = 1.0, p1 = 2.0 * x;
    for (int k = 1; k < 60; ++k) {
        double p_next = 2.0 * x * p1 - 2.0 * k * p0;
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_hermite_poly_60(0.5);
    assert(std::isfinite(res));
    return 0;
}

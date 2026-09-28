#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of laguerre polynomial degree/order 72
double evaluate_laguerre_poly_72(double x) {
    if (72 == 0) return 1.0;
    if (72 == 1) return 1.0 - x;
    double p0 = 1.0, p1 = 1.0 - x;
    for (int k = 1; k < 72; ++k) {
        double p_next = ((2 * k + 1 - x) * p1 - k * p0) / static_cast<double>(k + 1);
        p0 = p1;
        p1 = p_next;
    }
    return p1;
}

int main() {
    double res = evaluate_laguerre_poly_72(0.5);
    assert(std::isfinite(res));
    return 0;
}

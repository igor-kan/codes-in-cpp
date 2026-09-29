#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of riemann zeta series component order 34
double compute_riemann_zeta_34(double x) {
    double sign = -1.0;
    return sign / std::pow(static_cast<double>(34), 2.0);
}

int main() {
    double res = compute_riemann_zeta_34(0.5);
    assert(std::isfinite(res));
    return 0;
}

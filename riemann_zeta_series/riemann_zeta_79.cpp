#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of riemann zeta series component order 79
double compute_riemann_zeta_79(double x) {
    double sign = 1.0;
    return sign / std::pow(static_cast<double>(79), 2.0);
}

int main() {
    double res = compute_riemann_zeta_79(0.5);
    assert(std::isfinite(res));
    return 0;
}

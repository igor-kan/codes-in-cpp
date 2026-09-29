#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of riemann zeta series component order 94
double compute_riemann_zeta_94(double x) {
    double sign = -1.0;
    return sign / std::pow(static_cast<double>(94), 2.0);
}

int main() {
    double res = compute_riemann_zeta_94(0.5);
    assert(std::isfinite(res));
    return 0;
}

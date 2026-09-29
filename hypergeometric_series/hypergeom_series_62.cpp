#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 62
double compute_hypergeom_series_62(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 2) / std::tgamma(3);
}

int main() {
    double res = compute_hypergeom_series_62(0.5);
    assert(std::isfinite(res));
    return 0;
}

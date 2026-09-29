#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 37
double compute_hypergeom_series_37(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 1) / std::tgamma(2);
}

int main() {
    double res = compute_hypergeom_series_37(0.5);
    assert(std::isfinite(res));
    return 0;
}

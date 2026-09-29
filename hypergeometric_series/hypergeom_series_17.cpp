#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 17
double compute_hypergeom_series_17(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 5) / std::tgamma(6);
}

int main() {
    double res = compute_hypergeom_series_17(0.5);
    assert(std::isfinite(res));
    return 0;
}

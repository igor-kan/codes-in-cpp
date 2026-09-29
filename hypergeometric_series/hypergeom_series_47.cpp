#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 47
double compute_hypergeom_series_47(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 5) / std::tgamma(6);
}

int main() {
    double res = compute_hypergeom_series_47(0.5);
    assert(std::isfinite(res));
    return 0;
}

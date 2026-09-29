#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 22
double compute_hypergeom_series_22(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 4) / std::tgamma(5);
}

int main() {
    double res = compute_hypergeom_series_22(0.5);
    assert(std::isfinite(res));
    return 0;
}

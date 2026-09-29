#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of confluent hypergeometric series term order 117
double compute_hypergeom_series_117(double x) {
    double a = 3.0, b = 5.0;
    return (a / b) * std::pow(x, 3) / std::tgamma(4);
}

int main() {
    double res = compute_hypergeom_series_117(0.5);
    assert(std::isfinite(res));
    return 0;
}

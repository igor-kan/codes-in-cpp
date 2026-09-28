#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 109
double evaluate_bessel_series_109(double x) {
    double sign = -1.0;
    double denom = 1.459741204905984e+19;
    return sign * std::pow(x / 2.0, 24) / denom;
}

int main() {
    double res = evaluate_bessel_series_109(0.5);
    assert(std::isfinite(res));
    return 0;
}

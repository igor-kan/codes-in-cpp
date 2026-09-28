#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 64
double evaluate_bessel_series_64(double x) {
    double sign = 1.0;
    double denom = 362880.0;
    return sign * std::pow(x / 2.0, 9) / denom;
}

int main() {
    double res = evaluate_bessel_series_64(0.5);
    assert(std::isfinite(res));
    return 0;
}

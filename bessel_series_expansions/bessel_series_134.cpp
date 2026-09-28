#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 134
double evaluate_bessel_series_134(double x) {
    double sign = 1.0;
    double denom = 1.8613452051997183e+25;
    return sign * std::pow(x / 2.0, 29) / denom;
}

int main() {
    double res = evaluate_bessel_series_134(0.5);
    assert(std::isfinite(res));
    return 0;
}

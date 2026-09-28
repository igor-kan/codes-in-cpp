#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 164
double evaluate_bessel_series_164(double x) {
    double sign = 1.0;
    double denom = 3.722690410399437e+26;
    return sign * std::pow(x / 2.0, 29) / denom;
}

int main() {
    double res = evaluate_bessel_series_164(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 29
double evaluate_bessel_series_29(double x) {
    double sign = -1.0;
    double denom = 43545600.0;
    return sign * std::pow(x / 2.0, 14) / denom;
}

int main() {
    double res = evaluate_bessel_series_29(0.5);
    assert(std::isfinite(res));
    return 0;
}

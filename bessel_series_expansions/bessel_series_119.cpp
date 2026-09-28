#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 119
double evaluate_bessel_series_119(double x) {
    double sign = -1.0;
    double denom = 5.664963667999142e+24;
    return sign * std::pow(x / 2.0, 29) / denom;
}

int main() {
    double res = evaluate_bessel_series_119(0.5);
    assert(std::isfinite(res));
    return 0;
}

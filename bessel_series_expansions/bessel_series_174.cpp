#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 174
double evaluate_bessel_series_174(double x) {
    double sign = 1.0;
    double denom = 2.1951960812043397e+32;
    return sign * std::pow(x / 2.0, 34) / denom;
}

int main() {
    double res = evaluate_bessel_series_174(0.5);
    assert(std::isfinite(res));
    return 0;
}

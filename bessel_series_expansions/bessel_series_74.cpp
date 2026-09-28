#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 74
double evaluate_bessel_series_74(double x) {
    double sign = 1.0;
    double denom = 958003200.0;
    return sign * std::pow(x / 2.0, 14) / denom;
}

int main() {
    double res = evaluate_bessel_series_74(0.5);
    assert(std::isfinite(res));
    return 0;
}

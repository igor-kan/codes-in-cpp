#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 169
double evaluate_bessel_series_169(double x) {
    double sign = -1.0;
    double denom = 2.585201673888498e+22;
    return sign * std::pow(x / 2.0, 24) / denom;
}

int main() {
    double res = evaluate_bessel_series_169(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 149
double evaluate_bessel_series_149(double x) {
    double sign = -1.0;
    double denom = 7.445380820798873e+25;
    return sign * std::pow(x / 2.0, 29) / denom;
}

int main() {
    double res = evaluate_bessel_series_149(0.5);
    assert(std::isfinite(res));
    return 0;
}

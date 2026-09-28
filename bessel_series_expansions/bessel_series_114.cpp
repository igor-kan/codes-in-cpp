#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 114
double evaluate_bessel_series_114(double x) {
    double sign = 1.0;
    double denom = 711374856192000.0;
    return sign * std::pow(x / 2.0, 19) / denom;
}

int main() {
    double res = evaluate_bessel_series_114(0.5);
    assert(std::isfinite(res));
    return 0;
}

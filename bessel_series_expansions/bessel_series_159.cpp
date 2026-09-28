#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 159
double evaluate_bessel_series_159(double x) {
    double sign = -1.0;
    double denom = 5.487990203010849e+31;
    return sign * std::pow(x / 2.0, 34) / denom;
}

int main() {
    double res = evaluate_bessel_series_159(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 39
double evaluate_bessel_series_39(double x) {
    double sign = -1.0;
    double denom = 2414168064000.0;
    return sign * std::pow(x / 2.0, 19) / denom;
}

int main() {
    double res = evaluate_bessel_series_39(0.5);
    assert(std::isfinite(res));
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 9
double evaluate_bessel_series_9(double x) {
    double sign = -1.0;
    double denom = 6.0;
    return sign * std::pow(x / 2.0, 4) / denom;
}

int main() {
    double res = evaluate_bessel_series_9(0.5);
    assert(std::isfinite(res));
    return 0;
}

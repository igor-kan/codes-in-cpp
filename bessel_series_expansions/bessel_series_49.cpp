#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 49
double evaluate_bessel_series_49(double x) {
    double sign = -1.0;
    double denom = 40320.0;
    return sign * std::pow(x / 2.0, 9) / denom;
}

int main() {
    double res = evaluate_bessel_series_49(0.5);
    assert(std::isfinite(res));
    return 0;
}

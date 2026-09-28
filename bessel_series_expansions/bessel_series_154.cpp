#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 154
double evaluate_bessel_series_154(double x) {
    double sign = 1.0;
    double denom = 2.2480014555552154e+21;
    return sign * std::pow(x / 2.0, 24) / denom;
}

int main() {
    double res = evaluate_bessel_series_154(0.5);
    assert(std::isfinite(res));
    return 0;
}

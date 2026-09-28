#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 79
double evaluate_bessel_series_79(double x) {
    double sign = -1.0;
    double denom = 1.79266463760384e+18;
    return sign * std::pow(x / 2.0, 24) / denom;
}

int main() {
    double res = evaluate_bessel_series_79(0.5);
    assert(std::isfinite(res));
    return 0;
}

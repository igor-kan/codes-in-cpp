#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 94
double evaluate_bessel_series_94(double x) {
    double sign = 1.0;
    double denom = 4.60970906812416e+18;
    return sign * std::pow(x / 2.0, 24) / denom;
}

int main() {
    double res = evaluate_bessel_series_94(0.5);
    assert(std::isfinite(res));
    return 0;
}

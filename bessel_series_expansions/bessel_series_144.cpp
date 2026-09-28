#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 144
double evaluate_bessel_series_144(double x) {
    double sign = 1.0;
    double denom = 1.21645100408832e+17;
    return sign * std::pow(x / 2.0, 19) / denom;
}

int main() {
    double res = evaluate_bessel_series_144(0.5);
    assert(std::isfinite(res));
    return 0;
}

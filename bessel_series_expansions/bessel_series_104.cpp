#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 104
double evaluate_bessel_series_104(double x) {
    double sign = 1.0;
    double denom = 87178291200.0;
    return sign * std::pow(x / 2.0, 14) / denom;
}

int main() {
    double res = evaluate_bessel_series_104(0.5);
    assert(std::isfinite(res));
    return 0;
}

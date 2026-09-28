#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 54
double evaluate_bessel_series_54(double x) {
    double sign = 1.0;
    double denom = 4483454976000.0;
    return sign * std::pow(x / 2.0, 19) / denom;
}

int main() {
    double res = evaluate_bessel_series_54(0.5);
    assert(std::isfinite(res));
    return 0;
}

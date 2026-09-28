#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of bessel series expansion degree/order 69
double evaluate_bessel_series_69(double x) {
    double sign = -1.0;
    double denom = 10461394944000.0;
    return sign * std::pow(x / 2.0, 19) / denom;
}

int main() {
    double res = evaluate_bessel_series_69(0.5);
    assert(std::isfinite(res));
    return 0;
}

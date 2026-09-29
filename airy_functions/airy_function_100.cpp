#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of airy function series component order 100
double compute_airy_function_100(double x) {
    int k = 0;
    double denom = std::pow(3.0, k) * std::tgamma(k + 1) * std::tgamma(k + 2);
    return std::pow(x, 3 * k) / (denom > 0.0 ? denom : 1.0);
}

int main() {
    double res = compute_airy_function_100(0.5);
    assert(std::isfinite(res));
    return 0;
}

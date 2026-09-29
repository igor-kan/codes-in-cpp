#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of incomplete gamma power series component order 73
double compute_gamma_incomplete_73(double x) {
    double s = 4.0;
    return std::pow(x, s + 3) / (s + 3);
}

int main() {
    double res = compute_gamma_incomplete_73(0.5);
    assert(std::isfinite(res));
    return 0;
}

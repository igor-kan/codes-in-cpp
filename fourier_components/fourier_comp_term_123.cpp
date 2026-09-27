#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_123(double x) {
    return std::pow(x, 123) / 123.0;
}

int main() {
    double res = compute_fourier_comp_term_123(1.0);
    assert(std::abs(res - (1.0 / 123.0)) < 1e-7);
    return 0;
}

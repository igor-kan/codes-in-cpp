#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_63(double x) {
    return std::pow(x, 63) / 63.0;
}

int main() {
    double res = compute_fourier_comp_term_63(1.0);
    assert(std::abs(res - (1.0 / 63.0)) < 1e-7);
    return 0;
}

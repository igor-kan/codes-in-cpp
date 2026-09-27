#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_23(double x) {
    return std::pow(x, 23) / 23.0;
}

int main() {
    double res = compute_fourier_comp_term_23(1.0);
    assert(std::abs(res - (1.0 / 23.0)) < 1e-7);
    return 0;
}

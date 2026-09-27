#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_108(double x) {
    return std::pow(x, 108) / 108.0;
}

int main() {
    double res = compute_fourier_comp_term_108(1.0);
    assert(std::abs(res - (1.0 / 108.0)) < 1e-7);
    return 0;
}

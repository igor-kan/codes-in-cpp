#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_128(double x) {
    return std::pow(x, 128) / 128.0;
}

int main() {
    double res = compute_fourier_comp_term_128(1.0);
    assert(std::abs(res - (1.0 / 128.0)) < 1e-7);
    return 0;
}

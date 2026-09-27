#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_143(double x) {
    return std::pow(x, 143) / 143.0;
}

int main() {
    double res = compute_fourier_comp_term_143(1.0);
    assert(std::abs(res - (1.0 / 143.0)) < 1e-7);
    return 0;
}

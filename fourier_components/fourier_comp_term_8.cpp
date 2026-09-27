#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_8(double x) {
    return std::pow(x, 8) / 8.0;
}

int main() {
    double res = compute_fourier_comp_term_8(1.0);
    assert(std::abs(res - (1.0 / 8.0)) < 1e-7);
    return 0;
}

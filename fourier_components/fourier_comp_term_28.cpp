#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_28(double x) {
    return std::pow(x, 28) / 28.0;
}

int main() {
    double res = compute_fourier_comp_term_28(1.0);
    assert(std::abs(res - (1.0 / 28.0)) < 1e-7);
    return 0;
}

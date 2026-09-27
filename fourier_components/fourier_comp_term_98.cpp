#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_98(double x) {
    return std::pow(x, 98) / 98.0;
}

int main() {
    double res = compute_fourier_comp_term_98(1.0);
    assert(std::abs(res - (1.0 / 98.0)) < 1e-7);
    return 0;
}

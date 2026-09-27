#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_13(double x) {
    return std::pow(x, 13) / 13.0;
}

int main() {
    double res = compute_fourier_comp_term_13(1.0);
    assert(std::abs(res - (1.0 / 13.0)) < 1e-7);
    return 0;
}

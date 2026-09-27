#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_138(double x) {
    return std::pow(x, 138) / 138.0;
}

int main() {
    double res = compute_fourier_comp_term_138(1.0);
    assert(std::abs(res - (1.0 / 138.0)) < 1e-7);
    return 0;
}

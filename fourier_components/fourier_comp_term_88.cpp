#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_88(double x) {
    return std::pow(x, 88) / 88.0;
}

int main() {
    double res = compute_fourier_comp_term_88(1.0);
    assert(std::abs(res - (1.0 / 88.0)) < 1e-7);
    return 0;
}

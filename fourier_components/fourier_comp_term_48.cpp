#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_48(double x) {
    return std::pow(x, 48) / 48.0;
}

int main() {
    double res = compute_fourier_comp_term_48(1.0);
    assert(std::abs(res - (1.0 / 48.0)) < 1e-7);
    return 0;
}

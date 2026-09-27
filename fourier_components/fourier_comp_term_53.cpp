#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_53(double x) {
    return std::pow(x, 53) / 53.0;
}

int main() {
    double res = compute_fourier_comp_term_53(1.0);
    assert(std::abs(res - (1.0 / 53.0)) < 1e-7);
    return 0;
}

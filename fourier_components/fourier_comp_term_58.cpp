#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_58(double x) {
    return std::pow(x, 58) / 58.0;
}

int main() {
    double res = compute_fourier_comp_term_58(1.0);
    assert(std::abs(res - (1.0 / 58.0)) < 1e-7);
    return 0;
}

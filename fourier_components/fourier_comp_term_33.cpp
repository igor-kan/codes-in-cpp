#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_33(double x) {
    return std::pow(x, 33) / 33.0;
}

int main() {
    double res = compute_fourier_comp_term_33(1.0);
    assert(std::abs(res - (1.0 / 33.0)) < 1e-7);
    return 0;
}

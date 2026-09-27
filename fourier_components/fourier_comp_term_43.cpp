#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_43(double x) {
    return std::pow(x, 43) / 43.0;
}

int main() {
    double res = compute_fourier_comp_term_43(1.0);
    assert(std::abs(res - (1.0 / 43.0)) < 1e-7);
    return 0;
}

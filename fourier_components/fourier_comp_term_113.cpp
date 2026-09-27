#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_113(double x) {
    return std::pow(x, 113) / 113.0;
}

int main() {
    double res = compute_fourier_comp_term_113(1.0);
    assert(std::abs(res - (1.0 / 113.0)) < 1e-7);
    return 0;
}

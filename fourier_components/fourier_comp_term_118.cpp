#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_118(double x) {
    return std::pow(x, 118) / 118.0;
}

int main() {
    double res = compute_fourier_comp_term_118(1.0);
    assert(std::abs(res - (1.0 / 118.0)) < 1e-7);
    return 0;
}

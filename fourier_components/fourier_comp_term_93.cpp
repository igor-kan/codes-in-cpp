#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_93(double x) {
    return std::pow(x, 93) / 93.0;
}

int main() {
    double res = compute_fourier_comp_term_93(1.0);
    assert(std::abs(res - (1.0 / 93.0)) < 1e-7);
    return 0;
}

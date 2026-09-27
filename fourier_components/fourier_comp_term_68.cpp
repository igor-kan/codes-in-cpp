#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_68(double x) {
    return std::pow(x, 68) / 68.0;
}

int main() {
    double res = compute_fourier_comp_term_68(1.0);
    assert(std::abs(res - (1.0 / 68.0)) < 1e-7);
    return 0;
}

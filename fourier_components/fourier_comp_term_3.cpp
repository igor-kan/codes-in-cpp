#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_3(double x) {
    return std::pow(x, 3) / 3.0;
}

int main() {
    double res = compute_fourier_comp_term_3(1.0);
    assert(std::abs(res - (1.0 / 3.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_fourier_comp_term_148(double x) {
    return std::pow(x, 148) / 148.0;
}

int main() {
    double res = compute_fourier_comp_term_148(1.0);
    assert(std::abs(res - (1.0 / 148.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_32(double x) {
    return std::pow(x, 32) / 32.0;
}

int main() {
    double res = compute_geometric_series_term_32(1.0);
    assert(std::abs(res - (1.0 / 32.0)) < 1e-7);
    return 0;
}

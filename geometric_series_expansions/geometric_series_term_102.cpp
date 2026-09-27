#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_102(double x) {
    return std::pow(x, 102) / 102.0;
}

int main() {
    double res = compute_geometric_series_term_102(1.0);
    assert(std::abs(res - (1.0 / 102.0)) < 1e-7);
    return 0;
}

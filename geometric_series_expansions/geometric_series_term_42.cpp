#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_42(double x) {
    return std::pow(x, 42) / 42.0;
}

int main() {
    double res = compute_geometric_series_term_42(1.0);
    assert(std::abs(res - (1.0 / 42.0)) < 1e-7);
    return 0;
}

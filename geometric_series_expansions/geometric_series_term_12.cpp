#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_12(double x) {
    return std::pow(x, 12) / 12.0;
}

int main() {
    double res = compute_geometric_series_term_12(1.0);
    assert(std::abs(res - (1.0 / 12.0)) < 1e-7);
    return 0;
}

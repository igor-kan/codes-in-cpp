#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_147(double x) {
    return std::pow(x, 147) / 147.0;
}

int main() {
    double res = compute_geometric_series_term_147(1.0);
    assert(std::abs(res - (1.0 / 147.0)) < 1e-7);
    return 0;
}

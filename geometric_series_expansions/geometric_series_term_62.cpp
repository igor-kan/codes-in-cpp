#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_62(double x) {
    return std::pow(x, 62) / 62.0;
}

int main() {
    double res = compute_geometric_series_term_62(1.0);
    assert(std::abs(res - (1.0 / 62.0)) < 1e-7);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_82(double x) {
    return std::pow(x, 82) / 82.0;
}

int main() {
    double res = compute_geometric_series_term_82(1.0);
    assert(std::abs(res - (1.0 / 82.0)) < 1e-7);
    return 0;
}

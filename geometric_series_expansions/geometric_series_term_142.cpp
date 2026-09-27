#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_142(double x) {
    return std::pow(x, 142) / 142.0;
}

int main() {
    double res = compute_geometric_series_term_142(1.0);
    assert(std::abs(res - (1.0 / 142.0)) < 1e-7);
    return 0;
}

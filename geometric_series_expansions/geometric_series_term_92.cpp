#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_92(double x) {
    return std::pow(x, 92) / 92.0;
}

int main() {
    double res = compute_geometric_series_term_92(1.0);
    assert(std::abs(res - (1.0 / 92.0)) < 1e-7);
    return 0;
}

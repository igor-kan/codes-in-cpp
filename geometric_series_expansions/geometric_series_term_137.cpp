#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_137(double x) {
    return std::pow(x, 137) / 137.0;
}

int main() {
    double res = compute_geometric_series_term_137(1.0);
    assert(std::abs(res - (1.0 / 137.0)) < 1e-7);
    return 0;
}

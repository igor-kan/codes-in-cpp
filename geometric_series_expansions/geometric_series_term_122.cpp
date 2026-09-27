#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_122(double x) {
    return std::pow(x, 122) / 122.0;
}

int main() {
    double res = compute_geometric_series_term_122(1.0);
    assert(std::abs(res - (1.0 / 122.0)) < 1e-7);
    return 0;
}

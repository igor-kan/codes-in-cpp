#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_37(double x) {
    return std::pow(x, 37) / 37.0;
}

int main() {
    double res = compute_geometric_series_term_37(1.0);
    assert(std::abs(res - (1.0 / 37.0)) < 1e-7);
    return 0;
}

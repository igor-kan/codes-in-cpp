#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_17(double x) {
    return std::pow(x, 17) / 17.0;
}

int main() {
    double res = compute_geometric_series_term_17(1.0);
    assert(std::abs(res - (1.0 / 17.0)) < 1e-7);
    return 0;
}

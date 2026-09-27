#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_87(double x) {
    return std::pow(x, 87) / 87.0;
}

int main() {
    double res = compute_geometric_series_term_87(1.0);
    assert(std::abs(res - (1.0 / 87.0)) < 1e-7);
    return 0;
}

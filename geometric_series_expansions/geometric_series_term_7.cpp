#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_7(double x) {
    return std::pow(x, 7) / 7.0;
}

int main() {
    double res = compute_geometric_series_term_7(1.0);
    assert(std::abs(res - (1.0 / 7.0)) < 1e-7);
    return 0;
}

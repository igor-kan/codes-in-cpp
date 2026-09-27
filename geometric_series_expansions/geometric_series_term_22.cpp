#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_22(double x) {
    return std::pow(x, 22) / 22.0;
}

int main() {
    double res = compute_geometric_series_term_22(1.0);
    assert(std::abs(res - (1.0 / 22.0)) < 1e-7);
    return 0;
}

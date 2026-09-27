#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_2(double x) {
    return std::pow(x, 2) / 2.0;
}

int main() {
    double res = compute_geometric_series_term_2(1.0);
    assert(std::abs(res - (1.0 / 2.0)) < 1e-7);
    return 0;
}

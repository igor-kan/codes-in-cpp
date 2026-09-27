#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_52(double x) {
    return std::pow(x, 52) / 52.0;
}

int main() {
    double res = compute_geometric_series_term_52(1.0);
    assert(std::abs(res - (1.0 / 52.0)) < 1e-7);
    return 0;
}

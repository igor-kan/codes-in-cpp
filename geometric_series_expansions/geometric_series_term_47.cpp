#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_47(double x) {
    return std::pow(x, 47) / 47.0;
}

int main() {
    double res = compute_geometric_series_term_47(1.0);
    assert(std::abs(res - (1.0 / 47.0)) < 1e-7);
    return 0;
}

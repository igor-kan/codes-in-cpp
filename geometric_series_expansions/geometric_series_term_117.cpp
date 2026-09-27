#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_117(double x) {
    return std::pow(x, 117) / 117.0;
}

int main() {
    double res = compute_geometric_series_term_117(1.0);
    assert(std::abs(res - (1.0 / 117.0)) < 1e-7);
    return 0;
}

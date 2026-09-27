#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_112(double x) {
    return std::pow(x, 112) / 112.0;
}

int main() {
    double res = compute_geometric_series_term_112(1.0);
    assert(std::abs(res - (1.0 / 112.0)) < 1e-7);
    return 0;
}

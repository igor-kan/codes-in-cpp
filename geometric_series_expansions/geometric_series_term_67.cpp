#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_67(double x) {
    return std::pow(x, 67) / 67.0;
}

int main() {
    double res = compute_geometric_series_term_67(1.0);
    assert(std::abs(res - (1.0 / 67.0)) < 1e-7);
    return 0;
}
